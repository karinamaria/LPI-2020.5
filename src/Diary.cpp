#include "Diary.h"


Diary::Diary(const std::string& filename) : filename(filename), messages(nullptr), 
messages_size(0) {
	messages_capacity = 10;
	messages = new Message[messages_capacity];
}

void Diary::add(const std::string& message){
	
	if(messages_size >= messages_capacity){
		return;// interrompe a execução do método
	}
    messages[messages_size].content = message;
    messages_size++;
}

void Diary::write(){
    // gravar as mensagens no disco
}