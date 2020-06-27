#include "Hour.h"

#include <sstream>

Hour::Hour() : time(0), minute(0), second(0) {

}

void Hour::set_from_string(const std::string& tempo){
  std::stringstream stream(tempo);
  char discard;

  stream >> time;
  stream >> discard;
  stream >> minute;
  stream >> discard;
  stream >> second;
}

std::string Hour::to_string() {
  std::stringstream stream;
	if(time < 10){
    stream << "0";
  }
  stream << time;
	stream << ":";
  if(minute < 10){
    stream << "0";
  }
	stream << minute;
	stream << ":";
  if(second < 10){
    stream << '0';
  }
	stream << second;
  	
  return stream.str();
}
