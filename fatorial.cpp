#include <iostream>  // Biblioteca para entrada e saída

using namespace std;

int main() {
    int numero;
    int fatorial = 1;
    cout << "Informe um numero:";
    cin >> numero;
    if (numero == 0){
        fatorial = 1;
    }
    else{
        for (int i = 1; i <= numero; i++){
            fatorial = i * fatorial;
        }
    }
    cout << numero << "! = "<< fatorial << endl;
    
    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}