#ifndef HOUR_H
#define HOUR_H

#include <string>

struct Hour{
	Hour();

    unsigned time;
    unsigned minute;
    unsigned second;

    void set_from_string(const std::string& tempo);
    std::string to_string();
};
/****/
#endif