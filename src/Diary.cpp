#include "Diary.h"
#include "Util.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Diary::Diary(const std::string& filename) : filename(filename){
	loadDiary(filename);
}

Diary::~Diary(){
    write();
}

void Diary::add(const std::string& message){
	Message msg;
	msg.content = message;
	msg.date.set_from_string(get_current_date());
	msg.hour.set_from_string(get_current_time());
    messages.push_back(msg);
}

void Diary::add(const Message& message){
	messages.push_back(message);
}
void Diary::write(){
    std::ofstream arquivo_saida(filename);
    if (!arquivo_saida.is_open()) {
    	return;
  	}
  	for(Message& msg : messages){
  		std::string date_message = msg.date.to_string();
  		if(!existeDataNoArquivo(filename, date_message)){
			arquivo_saida << "# " << date_message << std::endl;
		}
		std::string hora = msg.hour.to_string();
		arquivo_saida << "- " << hora << " "<< msg.content << std::endl;
  	}
}

std::vector<Message*> Diary::search(const std::string& what){
	std::vector<Message*> msg_search;
	for(Message& msg : messages){
		if(msg.content.find(what) != std::string::npos){
			msg_search.push_back(&msg);
		}
	}
	return msg_search;
}

void Diary::loadDiary(const std::string& filename){	
	Message msg;
	
	std::ifstream arquivo(filename, std::ios::in | std::ios::app);
	if(!arquivo.is_open()){
		return;
	}
	std::string linha;
	while (!arquivo.eof()) {
    	std::getline(arquivo, linha);
    	if (linha.size() == 0) { //Contar quantidade de bytes da linha
      		continue;//se a qnt de bytes for zero, é iniciada a próxima interação do while
    	}
    	if(linha[0] == '#'){
    		msg.date.set_from_string(linha.substr(2));
    		continue;
    	}
    	msg.hour.set_from_string(linha.substr(2, 10));
    	msg.content = linha.substr(11);
    	add(msg);
  	}
}