#ifndef APP_H
#define APP_H

#include "Diary.h"

#include <string>

struct App{
    Diary diary;

    App(const std::string& filename);
    int run(int argc, char* argv[]);
    int show_usage();
    void add();
    void add(const std::string message);
    void list_messages();
    void search();
    void search(const std::string what);
};
#endif