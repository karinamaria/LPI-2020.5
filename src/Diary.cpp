#include "Diary.h"
#include "Util.h"

#include <fstream>
#include <iostream>
#include <string>

Diary::Diary(const std::string& filename) : filename(filename), messages(nullptr), 
messages_size(0), messages_capacity(10){
	messages = new Message[messages_capacity];
	loadDiary(filename);
}

Diary::~Diary(){
    delete[] messages;
}

void Diary::add(const std::string& message){
	
	if(messages_size >= messages_capacity){
		increaseArray();
	}
	Message msg;
	msg.content = message;
	msg.date.set_from_string(get_current_date());
	msg.hour.set_from_string(get_current_time());
    messages[messages_size] = msg;
    messages_size++;
}

void Diary::add(const Message& message){
	if(messages_size >= messages_capacity){
		increaseArray();
	}
	messages[messages_size] = message;
	messages_size++;
}
void Diary::write(){
    std::ofstream arquivo_saida(filename);
    if (!arquivo_saida.is_open()) {
    	return;
  	}
  	for(size_t i=0; i<messages_size; i++){
  		std::string date_message = messages[i].date.to_string();
		if(!existeDataNoArquivo(filename, date_message)){
			arquivo_saida << "# " << date_message << std::endl;
		}
		std::string hora = messages[i].hour.to_string();
		arquivo_saida << "- " << hora << " "<< messages[i].content << std::endl;
  	}
  	
}

Message* Diary::search(const std::string& what){
	for(size_t i=0; i<messages_size; i++){
		if(messages[i].content.find(what) != std::string::npos){
			return messages+i;
		}
	}
	return nullptr;
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

void Diary::increaseArray(){
	messages_capacity *= 2;
	Message* new_array = new Message[messages_capacity];
	for(size_t i=0; i<messages_size; i++){
		new_array[i] = messages[i];
	}
	delete[] messages;
	messages = new_array;
}