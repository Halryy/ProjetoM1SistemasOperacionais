// Versão sem cout e sem threads!! *****************************************************************************************************************
#include <iostream>
#include <iomanip>
using namespace std;
const long long unsigned int tamanhoY = 12000, tamanhoX = 12000;
int matrizA[tamanhoY][tamanhoX], matrizB[tamanhoY][tamanhoX], matrizAB[tamanhoY][tamanhoX];
void criaMatrizes() {
    int valoradorA = 1, valoradorB = tamanhoY * tamanhoX;
    for (int linha = 0; linha < tamanhoY; linha++) {
        for (int coluna = 0; coluna < tamanhoX; coluna++) {
            matrizA[linha][coluna] = valoradorA;
            valoradorA++;
        }
    }
    for (int linha = 0; linha < tamanhoY; linha++) {
        for (int coluna = 0; coluna < tamanhoX; coluna++) {
            matrizB[linha][coluna] = valoradorB;
            valoradorB--;
        }
    }
}
void calculaMatrizes() {
    int coluna = 0, linha = 0, linhaB = 0, colunaB = 0;
    for (linha = 0; linha < tamanhoY; linha++) {
        for (coluna = 0; coluna < tamanhoX; coluna++) {
            matrizAB[linha][coluna] = matrizA[linha][coluna] * matrizB[linha][coluna];
        }
    }
    for (linhaB = 0; linhaB < tamanhoY; linhaB++) {
        for (colunaB = 0; colunaB < tamanhoX; colunaB++) {
            matrizAB[linhaB][colunaB] = matrizA[linhaB][colunaB] * matrizB[colunaB][linhaB];
        }
    }
}
int main() {
    criaMatrizes();
    calculaMatrizes();
    //Comando para rodar no terminal: c++ p1Limitless.cpp -o a.out && time ./a.out
    // system("clear");
    return 0;
}
