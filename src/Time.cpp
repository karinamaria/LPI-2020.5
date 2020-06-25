#include "Time.h"

#include <sstream>

Time::Time() : hour(0), minute(0), second(0) {

}

void Time::set_from_string(const std::string& time){
	Time t;

    std::stringstream stream(time);
    char discard;

    stream >> t.hour;
    stream >> discard;
    stream >> t.minute;
    stream >> discard;
    stream >> t.second;
}

std::string Time::to_string() {
	std::stringstream stream;
	stream << hour;
	stream << "/";
	stream << minute;
	stream << "/";
	stream << second;
  	
  	return stream.str();
}
