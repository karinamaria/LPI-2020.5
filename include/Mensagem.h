#ifndef MENSAGEM_H
#define MENSAGEM_H

#include "Tempo.h"

#include <string>

struct Mensagem {
  Data data;
  Hora hora;
  std::string conteudo;
};

#endif