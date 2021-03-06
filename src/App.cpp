#include "App.h"

#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename){
}

int App::run(int argc, char* argv[]){
    if(argc == 1){
        return show_usage();
        return 1;
    }

    std::string action = argv[1];
    if(action != "add" && action != "list" && action != "search") {
        return show_usage();
        return 1;
    }

    if(action == "add"){
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }   
    }
    else if (action == "list") {
        list_messages();
    }else if (action == "search") {
        if (argc == 2) {
            search();
        } else {
            search(argv[2]);
        }   
    } else {
        return show_usage();
    }

    return 0;
}

void App::add(){
    std::string message;
    std::cout << "Enter your message: ";
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message){
    diary.add(message);
    diary.write();
}

void App::list_messages(){
    for (Message& message : diary.messages) {
        std::cout << "- " << message.content << std::endl;
    }
}

void App::search(){
    std::string what;
    std::cout << "Search for: ";
    std::getline(std::cin, what);

    search(what);
}

void App::search(const std::string what){
    std::vector<Message*> message = diary.search(what);
    if(message.empty()){
        std::cout << "Message not found" << std::endl;
        return;
    }
    for (Message* msg : message) {
        std::cout << "- " << msg->hour.to_string() << " ";
        std::cout << msg->content << std::endl;
    }
}

int App::show_usage(){
    return 1;
}