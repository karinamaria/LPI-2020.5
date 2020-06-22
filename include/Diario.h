#ifndef DIARIO_H
#define DIARIO_H

#include "Mensagem.h"

struct Diario {
  std::string nomeArquivo;
  Mensagem *mensagens;

  void adicionarMensagem();
  void listarMensagens();
};

#endif