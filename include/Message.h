#ifndef MESSAGE_H
#define MESSAGE_H

#include "Date.h"
#include "Hour.h"

#include <string>

struct Message{
    std::string content;
    Date date;
    Hour hour;
};
#endif