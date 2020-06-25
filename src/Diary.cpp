#include "Diary.h"

Diary::Diary(const std::string& filename) : filename(filename), messages(nullptr), 
messages_size(0), messages_capacity(10){
	messages = new Message[messages_capacity];
}

Diary::~Diary(){
    delete[] messages;
}

void Diary::add(const std::string& message){
	
	if(messages_size >= messages_capacity){
		return;// interrompe a execução do método
	}
	Message msg;
	msg.content = message;
	//msg.date.set_from_string_date("");
	//msg.time.set_from_string_time("");
    messages[messages_size] = msg;
    messages_size++;
}

void Diary::write(){
    // gravar as mensagens no disco
}