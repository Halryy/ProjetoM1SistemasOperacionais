#include <iostream>
using namespace std;
const int tamanho = 40000;
int array[tamanho];
void criaVetor(){
    int index = 0;
    for (int i = tamanho; i != 0; i--)
    {
        array[index] = i;
        cout << "Antes de ordenar: " << array[index] << endl;
        index++;
    }
}
void ordenaVetor() {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (array[j] > array[i]) {
                int aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }
}
void printaVetor() {
    for (int i = 0; i < tamanho; i++) {
        cout << "Após ordenar: " << array[i] << endl;
    }
}
int main()
{
    system("clear");
    criaVetor();
    ordenaVetor();
    cout << endl;
    printaVetor();
    // Comando para rodar no terminal: c++ p2.cpp -o a.out && time ./a.out
    return 0;
}