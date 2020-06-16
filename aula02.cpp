#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::string mensagem;
	
	if(argc == 1 || (argc > 1 && std::string(argv[1]) != "add")){
		std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
	}else if(argc > 2){
		for(int i = 2; i < argc; i++){
			mensagem.append(argv[i]);
			mensagem.append(" ");
		}
		std::cout << mensagem << std::endl;
	}else{
		std::cout << "Informe a mensagem: ";
		std::getline(std::cin, mensagem);
		std::cout << mensagem << std::endl;
	}
  	return 0;
}