#include "Time.h"

#include <sstream>

Time::Time() : hour(0), minute(0), second(0) {

}

void set_from_string_time(const std::string& time){
	Time t;

    std::stringstream stream(time);
    char discard;

    stream >> t.hour;
    stream >> discard;
    stream >> t.minute;
    stream >> discard;
    stream >> t.second;
}


