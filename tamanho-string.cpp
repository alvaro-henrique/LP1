# include <iostream>
# include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string texto;
    cout << "Informe uma frase ou uma palavra:" << endl; 
    getline (cin,texto);
    cout << "Sua frase/palavra possui: " << texto.size() << " caractere(s)";
    return 0;
}
