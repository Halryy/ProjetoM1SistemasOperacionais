#include <iostream>
#include <thread>
using namespace std;
const int tamanho = 40000;
int arrayDeValores[tamanho];
void criaVetor(){
    int index = 0;
    for (int i = tamanho; i != 0; i--)
    {
        arrayDeValores[index] = i;
        index++;
    }
}
void printaVetor() {
    for (int i = 0; i < tamanho; i++) {
        cout << "Antes de ordenar: " << arrayDeValores[i] << endl;
    }
}
void ordenaVetor() {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (arrayDeValores[j] > arrayDeValores[i]) {
                int aux = arrayDeValores[j];
                arrayDeValores[j] = arrayDeValores[i];
                arrayDeValores[i] = aux;
            }
        }
    }
}
void printaVetorAposOrdenar() {
    for (int i = 0; i < tamanho; i++) {
        cout << "Após ordenar: " << arrayDeValores[i] << endl;
    }
}
int main()
{
    system("clear");
    std::thread t1(criaVetor);
    std::thread t2(printaVetor);
    std::thread t3(ordenaVetor);
    std::thread t4(printaVetorAposOrdenar);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    // Comando para rodar no terminal: c++ p2Threading.cpp -o a.out && time ./a.out
    return 0;
}