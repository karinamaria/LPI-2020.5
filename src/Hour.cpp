#include "Hour.h"

#include <sstream>

Hour::Hour() : time(0), minute(0), second(0) {

}

void Hour::set_from_string(const std::string& time){
	Hour t;

  std::stringstream stream(time);
  char discard;

  stream >> t.time;
  stream >> discard;
  stream >> t.minute;
  stream >> discard;
  stream >> t.second;
}

std::string Hour::to_string() {
  std::stringstream stream;
	stream << time;
	stream << ":";
	stream << minute;
	stream << ":";
	stream << second;
  	
  return stream.str();
}
