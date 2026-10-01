#include <iostream>

using namespace std;

int main() {
    char op;
    float n1, n2;

    cout << "Somar  | + | Subtrair | - | Multiplicar | * | Dividir | / |" << endl;
    cout << "Escolha a operacao: ";
    cin >> op;

    cout << "Numero 1: ";
    cin >> n1;
    cout << "Numero 2: ";
    cin >> n2;

    if (op == '+') {
        cout << "Soma: " << (n1 + n2) << endl;
    }
    else if (op == '-') {
        cout << "Subtracao: " << (n1 - n2) << endl;
    }
    else if (op == '*') {
        cout << "Multiplicacao: " << (n1 * n2) << endl;
    }
    else if (op == '/') {
        if (n2 != 0) {
            cout << "Divisao: " << (n1 / n2) << endl;
        }
        else {
            cout << "Erro: divisao por zero" << endl;
        }
    }
    else {
        cout << "Es burro." << endl;
    }
}
