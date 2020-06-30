#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>

struct Diary{
    Diary(const std::string& filename);
    ~Diary();
    
    std::string filename;
    Message* messages;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string& message);
    void add(const Message& message);
    void write();
    Message* search(const std::string& what);
    void loadDiary(const std::string& filename);
    void increaseArray();
};
#endif