#include <iostream>
#include <fstream>
#include <string>

void mostrarUso(const std::string &nomePrograma);
int adicionarMensagemNoArquivo(std::string mensagem);
int lerArquivo();

int main(int argc, char *argv[]) {

	if(argc == 1){
		mostrarUso(argv[0]);
		return 1;
	}

	std::string acao = argv[1];
	if(acao != "add" && acao != "list") {
		mostrarUso(argv[0]);
		return 1;
	}

	if(acao == "add"){
		std::string mensagem = (argc == 2) ? "" : argv[2];
		if(argc == 2){
			std::cout << "Informe a mensagem: ";
			std::getline(std::cin, mensagem);
		}
		return adicionarMensagemNoArquivo(mensagem);
	}
	if(acao == "list"){
		
		return lerArquivo();
	}
	
	
  	return 0;
}

void mostrarUso(const std::string &nomePrograma) {
  std::cout << "Uso: " << nomePrograma << " add <mensagem>" << std::endl;
  std::cout << "Uso: " << nomePrograma << " list" << std::endl;
}

int adicionarMensagemNoArquivo(std::string mensagem){
	std::ofstream arquivo("arquivo.txt", std::ios::app);

	if (!arquivo.is_open()) {
   		std::cerr << "Arquivo não existente ou sem permissão de leitura." << std::endl;
    	return 1;
  	}
	arquivo << mensagem << std::endl;
	std::cout << "Mensagem adicionada!" << std::endl;

	arquivo.close();
	return 0;
}

int lerArquivo(){
	std::ifstream arquivo("arquivo.txt");

	if (!arquivo.is_open()) {
   		std::cerr << "Arquivo não existente ou sem permissão de leitura." << std::endl;
    	return 1;
  	}

  	std::string message;

  	int numeroLinha = 0;

  	while (!arquivo.eof()) {
    	++numeroLinha;
    	std::getline(arquivo, message);
    	if (message.size() == 0) { //Contar quantidade de bytes da linha
      		continue;//se a qnt de bytes for zero, é iniciada a próxima interação do while
    	}

    	std::cout << numeroLinha << ". " << message << std::endl;
  	}

  	arquivo.close();

  	return 0;
}