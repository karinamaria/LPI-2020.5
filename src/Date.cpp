#include "Date.h"

#include <sstream>

Date::Date() : year(0), month(0), day(0) {
}
void set_from_string_date(const std::string& date){
	Date d;

    std::stringstream stream(date);
    char discard;

    stream >> d.day;
    stream >> discard;
    stream >> d.month;
    stream >> discard;
    stream >> d.year;
}