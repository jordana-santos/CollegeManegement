#include <iostream>
#include <exception>
#include <memory>
#include <string>

#include "../../include/menu/Controller.hpp"
#include "../../include/menu/Menu.hpp"

using namespace std;

int main() {
    Controller controller;
    cout<<" - Seja bem vindo ao sistema!"<<endl;

    try {
		(make_unique<Controller>())->start(); //Controler*
	} catch (const exception &myException) {
		cout<<" - Houve um problema inesperado. Tente executar o programa novamente! "<< string(myException.what());
		exit(1);
	}

    cout<<" - Obrigado por utilizar o sistema! Até a próxima..."<<endl;

    return 0;
}