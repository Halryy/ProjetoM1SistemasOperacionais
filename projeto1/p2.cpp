#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

const long unsigned int tamanhoY = 12000, tamanhoX = 12000;
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
    int totalOperacoes = tamanhoY * tamanhoX;
    int operacoesConcluidas = 0;

    for (linha = 0; linha < tamanhoY; linha++) {
        for (coluna = 0; coluna < tamanhoX; coluna++) {
            matrizAB[linha][coluna] = matrizA[linha][coluna] * matrizB[linha][coluna];
            operacoesConcluidas++;

            // Atualiza o indicador de progresso a cada 1% concluído
            if (operacoesConcluidas % (totalOperacoes / 100) == 0) {
                cout << "\rProgresso: " << (operacoesConcluidas * 100) / totalOperacoes << "%";
                cout.flush();
            }
        }
    }
}

int main() {
    auto startTime = high_resolution_clock::now();
    criaMatrizes();
    cout << "Calculando matrizes, aguarde..." << endl;
    calculaMatrizes();
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stopTime - startTime);
    cout << "\nTempo necessário para terminar a operação: " << duration.count() << " segundos." << endl;
    return 0;
}
