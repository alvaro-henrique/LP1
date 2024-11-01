#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    string nome;
    string cpf;
    
public:
    // Construtor para inicializar cliente com nome e CPF
    Cliente(string m, string a) : nome(m), cpf(a) {}

    // Métodos para obter os valores do cliente
    string getNome() {
        return nome;
    }
    
    string getCPF() {
        return cpf;
    }

};

class ContaBancaria {
private:
    int numero;
    Cliente cliente;
    double saldo;
    
public:
    
    // Construtor para inicializar a conta bancária com numero da conta, cliente e saldo com valor padrão zero
    ContaBancaria(int n, Cliente e, double a = 0.0) : numero(n), cliente(e), saldo(a){}
    
    // Metódo para exibir o saldo
    void exibirSaldo() {
        cout << "Saldo atual da conta " << numero <<  ": R$ " << saldo << endl;
    }
    
    // Metódo para validar se o valor de saque é menor que o saldo disponível
    bool validarSaldo(double valor) {
        if (saldo > valor){
            return true;
        }else{
            cout << "Saldo Insuficiente." << endl;
            return false;
        }
        
    }
    
    // Método para sacar o valor de uma conta
    void sacar(double saque) {
        if (validarSaldo(saque) == true){
            saldo = saldo - saque;
        }
    }
    
    // Método para depositar o valor em uma conta
    void depositar(double deposito) {
        saldo = saldo + deposito;
    }
    
    // Metódo para transferir um valor de uma conta para outra
    void transferir(double valor, ContaBancaria &destino) {
        if (validarSaldo(valor) == true){
            sacar(valor);
            destino.depositar(valor);
            cout << "Transferido: R$ " << valor <<  " da conta " << numero << " ";
            cout << "para a conta "<< destino.numero << endl;
        }else{
            cout << "Operação cancelada." << endl;
        }
    }
    
    // Metódo para transferir um valor dividido de uma conta para outras duas
    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
        if (validarSaldo(valor) == true){
            sacar(valor/2);
            destino1.depositar(valor/2);
            destino2.depositar(valor/2);
            cout << "Transferido: R$ " << valor/2 << " ";
            cout << "para cada conta (" << destino1.numero << " e " << destino2.numero << ") ";
            cout << "da conta " << numero << endl;
        }else{
            cout << "Operação cancelada." << endl;
        }
    }
    
    // Método para exibir as informações de usuário e conta
    void exibirInformacoes() {
        cout << "Titular: " << cliente.getNome() << ", CPF: " << cliente.getCPF() << endl;
        cout << "Número da Conta: " << numero << ", Saldo: R$ " << saldo << endl;
    }
};


int main() {
    // Criar um objeto da classe Carro
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");
    
    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    // Exibe o saldo inicial da conta de Ana
    conta1.exibirSaldo();
    
    // Ana transfere R$200 para Bruno
    conta1.transferir(200.0, conta2);
    
    // Ana transfere R$300 divididos entre Bruno e Carla
    conta1.transferir(300.0, conta2, conta3);
    
    cout << endl;
    
    // Ana transfere valor acima do saldo que possui para Bruno
    conta1.transferir(7000.0, conta2);
    
    // Ana transfere valor acima do saldo que possui entre Bruno e Carla
    conta1.transferir(8000.0, conta2, conta3);

    // Exibição dos saldos finais
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
