#include <iostream>
#include <fstream>

using namespace std;

// Declaracion de funciones
int recorrer(int cartas[], int n_cartas);

int main() {
    int n; // Numero de casos

    ifstream entrada ("cartas.txt");
    // En caso de que no se encuentre el re malparido archivo
    if (!entrada) cout << "No se encontro el re malparido archivo" << endl;

    entrada >> n;
    
    // Para cada caso
    for (int i = 0; i < n; i++) {
        int n_cartas; // Numero de cartas
        entrada >> n_cartas;

        int cartas[n_cartas];
        
        // Guardar cartas
        for (int j = 0; j < n_cartas; j++) {
            entrada >> cartas[j];
        }

        int aplausos = recorrer(cartas, n_cartas);
        cout << aplausos << endl;
    }
}

int recorrer(int cartas[], int n_cartas) {
    int n_buscado = 1;
    int aplausos = 0;
    int i = 0;

    while ((cartas[i] != n_cartas) || (n_buscado != n_cartas)) {
        if (cartas[i] != n_buscado) {
            if (i+1 == n_cartas) {
                i = 0;
                aplausos++;
            } else {
                i++;
            }
        } else {
            n_buscado++;
        }
    }
    
    return aplausos;
}
