#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int lista[5];
    int somalista = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "Digite o numero " << i <<":" << endl; 
        cin >> lista[i];
        somalista = lista[i] + somalista;
    }

    cout << "Soma é igual: " << somalista << endl;
    
    cout << "A lista é: ";
    
    for (int i = 0; i < 5; i++)
    {
        cout << lista[i]; 
    }
    return 0;
}
