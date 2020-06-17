#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	
	if(argc == 1){
		std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
		return 1;
	}

	std::string primeiroArgumento = argv[1];
	if(primeiroArgumento != "add"){
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
	std::cout << "Mensagem adicionada!" << std::endl;
	
  	return 0;
}