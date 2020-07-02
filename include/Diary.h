#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>
#include <vector>

struct Diary{
    Diary(const std::string& filename);
    ~Diary();
    
    std::string filename;
    std::vector<Message> messages;

    void add(const std::string& message);
    void add(const Message& message);
    void write();
    std::vector<Message*> search(const std::string& what);
    void loadDiary(const std::string& filename);
    void increaseArray();
};
#endif