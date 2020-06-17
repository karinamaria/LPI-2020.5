#include <iostream>
#include <string>

void mostrarMensagem(const std::string &nomePrograma);

int main(int argc, char *argv[]) {
	
	if(argc == 1){
		mostrarMensagem(argv[0]);
		return 1;
	}

	std::string primeiroArgumento = argv[1];
	if(primeiroArgumento != "add"){
		mostrarMensagem(argv[0]);
		return 1;
	}

	std::string mensagem;
	if(argc == 2){
		std::cout << "Informe a mensagem: ";
		std::getline(std::cin, mensagem);
	}else{
		mensagem = argv[2];
	}
	std::cout << "Mensagem adicionada!" << std::endl;
	
  	return 0;
}

void mostrarMensagem(const std::string &nomePrograma){
	std::cout << "Uso: " << *nomePrograma << " add <mensagem>" << std::endl;
}