
#include <iostream>
#include "/opt/homebrew/opt/libomp/include/omp.h"
#include <ctime>
#include <cstdlib>

// Tarea 1
// Autor: Josep Romagosa Llorden
// Matricula: A01374637

using namespace std;

int main() {
    int n = 1000;
    int a[n], b[n], c[n];

    srand(time(0));

    // Creamos los arreglos con numeros aleatorios
    for (int i = 0; i < n; i++) {
        a[i] = (rand() % 10) + 1;
        b[i] = (rand() % 10) + 1;
    }

    // Imprimir arreglo A

    cout << "Arreglo A: ";

    int sizeA = 10;
 
    std::copy(a, a + sizeA,
            std::ostream_iterator<int>(std::cout, " "));

    // Imprimir arreglo B

    cout << endl << "Arreglo B: ";

    int sizeB = 10;
 
    std::copy(b, b + sizeB,
            std::ostream_iterator<int>(std::cout, " "));

    // Iniciar sección paralela con OpenMP
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }

    // Imprimir arreglo C para revisar
    cout << endl << "Arreglo C: ";

    int sizeC = 10;
 
    std::copy(c, c + sizeC,
            std::ostream_iterator<int>(std::cout, " "));

    return 0;
}