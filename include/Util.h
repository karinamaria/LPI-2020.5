#ifndef UTIL_H
#define UTIL_H

#include <string>

std::string format_current_date(const std::string &format);
std::string get_current_date();
std::string get_current_time();
bool existeDataNoArquivo(const std::string& filename, std::string titulo);
/****/
#endif