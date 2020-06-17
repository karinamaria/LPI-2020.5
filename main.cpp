#include <iostream>
#include <fstream>
#include <string>

void adicionarMensagemNoArquivo(std::string mensagem);

int main(int argc, char *argv[]) {
	
	if(argc == 1 || (argc > 1 && std::string(argv[1]) != "add")){
		std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
		return 1;
	}

	std::string mensagem;
	if(argc == 2){
		std::cout << "Informe a mensagem: ";
		std::getline(std::cin, mensagem);
	}else{
		mensagem = argv[2];
	}

	adicionarMensagemNoArquivo(mensagem);
	
	
  	return 0;
}

void adicionarMensagemNoArquivo(std::string mensagem){
	std::ofstream arquivo("arquivo.txt", std::ios::app);
	
	arquivo << mensagem;
	std::cout << "Mensagem adicionada!" << std::endl;

	arquivo.close();
	
}