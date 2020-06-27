#include "Util.h"

#include <string>
#include <ctime>
#include <fstream>

std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { 
  return format_current_date("%d/%m/%Y"); 
}

std::string get_current_time() { 
  return format_current_date("%H:%M:%S"); 
}

bool existeDataNoArquivo(const std::string& filename, std::string titulo){
  std::ifstream arquivo_entrada(filename);
  std::string message;
  while (!arquivo_entrada.eof()) {
    std::getline(arquivo_entrada, message);
    if(message.size() != 0){      
      if(message[0] == '#' &&  message.erase(0,2) == titulo) {
        return true;
      } 
    }
  }
  return false;
}