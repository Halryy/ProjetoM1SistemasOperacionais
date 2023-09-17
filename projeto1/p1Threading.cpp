// Versão com couts e com threads!!!! ***************************************************************************************************
#include <iostream>
#include <iomanip>
#include <thread>
using namespace std;
const int tamanhoY = 3, tamanhoX = 3;
int matrizA[tamanhoX][tamanhoY], matrizB[tamanhoX][tamanhoY], matrizAB[tamanhoX][tamanhoY];
void criaMatrizes() {
    int valoradorA = 1, valoradorB = tamanhoY * tamanhoX;
    for (int linha = 0; linha < tamanhoY; linha++) {
        cout << "Matriz A: ";
        for (int coluna = 0; coluna < tamanhoX; coluna++) {
            matrizA[linha][coluna] = valoradorA;
            valoradorA++;
            cout << "[" << matrizA[linha][coluna] << "]" << " | ";
        }
        cout << "Matriz B: ";
        for (int coluna = 0; coluna < tamanhoX; coluna++) {
            matrizB[linha][coluna] = valoradorB;
            valoradorB--;
            cout << "[" <<matrizB[linha][coluna] << "]" << " | ";
        }
        cout << endl;
    }
}
void calculaMatricial() {
    int coluna = 0, linha = 0;
    cout << "\nMultiplicação matricial:\n";
    for (linha = 0; linha < tamanhoY; linha++) {
        cout << "Matriz AB: ";
        for (coluna = 0; coluna < tamanhoX; coluna++) {
            matrizAB[linha][coluna] = matrizA[linha][coluna] * matrizB[coluna][linha];
            cout << "[" << matrizA[linha][coluna] << "] x [" << matrizB[coluna][linha] << "] = " << setw(2) << matrizAB[linha][coluna] << " | ";
        }
        cout << endl;
    }
}
void calculaPosicional() {
    cout << "\nMultiplicação posicional:\n";
    int coluna = 0, linha = 0;
    for (linha = 0; linha < tamanhoY; linha++) {
        cout << "Matriz A@B: ";
        for (coluna = 0; coluna < tamanhoX; coluna++) {
            matrizAB[linha][coluna] = matrizA[linha][coluna] * matrizB[linha][coluna];
            cout << "[" << matrizA[linha][coluna] << "] x [" << matrizB[linha][coluna] << "] = " << setw(2) << matrizAB[linha][coluna] << " | ";
        }
        cout << endl;
    }
}
int main() {
    cout << endl;
    std::thread t1(criaMatrizes);
    std::thread t2(calculaMatricial);
    std::thread t3(calculaPosicional);
    t1.join();
    t2.join();
    t3.join();
    // system("clear");
    //Comando para rodar no terminal: c++ p1Threading.cpp -o a.out && time ./a.out
    return 0;
}
