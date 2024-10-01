#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int numero;
    bool primo = true;
    cout << "Informe o número: " << endl;
    cin >> numero;

    if (numero < 2){
        primo = false;
    }else{
        for (int i = 2; i < numero; i++){
            if(numero % i == 0){
                primo = false;
            }
        }
    }

    if(primo == true){
        cout << "É primo";
    }else{
        cout << "Não é primo";
    }

    return 0;
}
