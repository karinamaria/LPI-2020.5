#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <fstream>

void mostrarUso(const std::string &nomePrograma);
void adicionarMensagemNoArquivo(std::ifstream &arquivo_entrada, std::ofstream &arquivo_saida, std::string mensagem);
bool existeTituloNoArquivo(std::ifstream &arquivo, std::string titulo);
void lerArquivo(std::ifstream &arquivo);

std::string format_current_date(const std::string &format);
std::string get_current_date();
std::string get_current_time();

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

	std::ifstream arquivo_entrada("arquivo.md");
	std::ofstream arquivo_saida("arquivo.md", std::ios::app);

	if(acao == "add"){
		std::string mensagem = (argc == 2) ? "" : argv[2];
		if(argc == 2){
			std::cout << "Informe a mensagem: ";
			std::getline(std::cin, mensagem);
		}
		if (!arquivo_saida.is_open() || !arquivo_entrada.is_open() || arquivo_entrada.fail()) {
   			std::cerr << "Arquivo não existente ou sem permissão de leitura." << std::endl;
    		return 1;
  		}
		adicionarMensagemNoArquivo(arquivo_entrada, arquivo_saida, mensagem);
	}
	else if(acao == "list"){
		if (!arquivo_entrada.is_open() || arquivo_entrada.fail()) {
   			std::cerr << "Arquivo não existente ou sem permissão de leitura." << std::endl;
    		return 1;
  		}
		lerArquivo(arquivo_entrada);
	}
	
	
  	return 0;
}

void mostrarUso(const std::string &nomePrograma) {
  std::cout << "Uso: " << nomePrograma << " add <mensagem>" << std::endl;
  std::cout << "Uso: " << nomePrograma << " list" << std::endl;
}

void adicionarMensagemNoArquivo(std::ifstream &arquivo_entrada, std::ofstream &arquivo_saida, std::string mensagem){
	std::string diaAtual = get_current_date();
	if(!existeTituloNoArquivo(arquivo_entrada, diaAtual)){
		arquivo_saida << "# " << diaAtual << std::endl;
	}
	std::string horaAtual = get_current_time();
	arquivo_saida << "- " << horaAtual << " "<< mensagem << std::endl;
	std::cout << "Mensagem adicionada!" << std::endl;

}

bool existeTituloNoArquivo(std::ifstream &arquivo, std::string titulo){
	bool existeTitulo = false;
	std::string message;
	while (!arquivo.eof()) {
    	std::getline(arquivo, message);
    	if(message.size() != 0){  		
    		if(message[0] == '#' &&  message.erase(0,2) == titulo) {
    			existeTitulo = true;
  			} 
    	}
  	}
  	return existeTitulo;
}


void lerArquivo(std::ifstream &arquivo){
  	std::string message;

  	while (!arquivo.eof()) {
    	std::getline(arquivo, message);
    	if (message.size() == 0 || message[0] == '#') { //Contar quantidade de bytes da linha
      		continue;//se a qnt de bytes for zero, é iniciada a próxima interação do while
    	}
    	
    	std::cout << message << std::endl;
  	}

}

std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { return format_current_date("%d/%m/%Y"); }

std::string get_current_time() { return format_current_date("%H:%M:%S"); }