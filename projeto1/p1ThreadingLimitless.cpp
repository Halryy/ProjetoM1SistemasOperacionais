// Versão sem couts e com threads!!!! ***************************************************************************************************
// MÁXIMO DESEMPENHO!!!!!!!
#include <iostream>
#include <iomanip>
#include <thread>
#include <algorithm>
using namespace std;
const long long unsigned int tamanhoY = 12000, tamanhoX = 12000;
int matrizA[tamanhoX][tamanhoY], matrizB[tamanhoX][tamanhoY], matrizAB[tamanhoX][tamanhoY];
void criaMatrizes() {
    int valoradorA = 1, valoradorB = tamanhoY * tamanhoX;
    for (int linha = 0; linha < tamanhoY; linha++) {
        for (int coluna = 0; coluna < tamanhoX; coluna++) {
            matrizA[linha][coluna] = valoradorA;
            valoradorA++;
        }
        for (int coluna = 0; coluna < tamanhoX; coluna++) {
            matrizB[linha][coluna] = valoradorB;
            valoradorB--;
        }
    }
}
void calculaMatricial() {
    int coluna = 0, linha = 0;
    for (linha = 0; linha < tamanhoY; linha++) {
        for (coluna = 0; coluna < tamanhoX; coluna++) {
            matrizAB[linha][coluna] = matrizA[linha][coluna] * matrizB[coluna][linha];
        }
    }
}
void calculaPosicional() {
    int coluna = 0, linha = 0;
    for (linha = 0; linha < tamanhoY; linha++) {
        for (coluna = 0; coluna < tamanhoX; coluna++) {
            matrizAB[linha][coluna] = matrizA[linha][coluna] * matrizB[linha][coluna];
        }
    }
}
int main() {
    std::thread t1(criaMatrizes);
    std::thread t2(calculaMatricial);
    std::thread t3(calculaPosicional);
    t1.join();
    t2.join();
    t3.join();
    // system("clear");
    //Comando para rodar no terminal: c++ p1ThreadingLimitless.cpp -o a.out && time ./a.out
    return 0;
}
