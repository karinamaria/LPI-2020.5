#ifndef TEMPO_H
#define TEMPO_H

struct Data {
  int dia;
  int mes;
  int ano;
};

struct Hora {
  int hora;
  int minuto;
  int segundo;
};

Data mostrarData();
Hora mostrarHora();
bool dataJaCadastrada(Data dataMensagem, Data dataAtual);

#endif