// Versão com cout e sem threads **************************************************************************************************************
#include <iostream>
#include <iomanip>
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
    criaMatrizes();
    cout << "\nMultiplicação matricial:\n";
    calculaMatricial();
    cout << "\nMultiplicação posicional:\n";
    calculaPosicional();
    //// c++ p1.cpp -o a.out && time ./a.out
    system("clear");
    return 0;
}
