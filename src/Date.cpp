#include "Date.h"

#include <sstream>

Date::Date() : year(0), month(0), day(0) {
}
void Date::set_from_string(const std::string& date){
	Date d;

    std::stringstream stream(date);
    char discard;

    stream >> d.day;
    stream >> discard;
    stream >> d.month;
    stream >> discard;
    stream >> d.year;
}
std::string Date::to_string() {
	std::stringstream stream;
	stream << day;
	stream << "/";
	stream << month;
	stream << "/";
	stream << year;
  	
  	return stream.str();
}