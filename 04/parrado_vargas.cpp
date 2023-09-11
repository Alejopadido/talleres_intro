//  Integrantes:
//      * Alejandro Parrado
//      * Sebastian Vargas

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//hola
//bienvenido :D

int llenar(int agua[], int luz[], int gas[], int n);
int encontrarmenor(int agua[], int luz[], int gas[], int n);
void promedio(int agua[], int luz[], int gas[], int n, int promedios[]);
int subsidios(int agua[], int subsidio[], int promedios[], int n);

// main
int main() {
    int n; // es n
    int agua[20], luz[20], gas[20]; // crea los arreglos agua, luz, gas
    int promedios[3]; //crea el arreglo promedios
    int subsidio[10]; // crea el arreglo subsidios
    string nombres[3] = {"luz","agua","gas"}; // nombres de servicios 

    n = llenar(agua, luz, gas, n);

    int menor = encontrarmenor(agua, luz, gas, n); 
    cout<<"gasto menor: "<<menor<<endl; 

    promedio(agua, luz, gas, n, promedios);

    for (int i = 0; i <3; i++) // corazon <3
    {
        cout << "promedio " << nombres[i] << ": " << promedios[i] << "\n";
    }

    subsidios(agua, subsidio, promedios, n);
}

// Llena
int llenar(int agua[], int luz[], int gas[], int n) {
    ifstream entrada ("servicios.txt");
    if (!entrada) {
        cout << "Archivo no encontrado";
        exit(1);
    }
    entrada >> n;
    
    for (int i = 0; i < n; i++) {
        entrada>>luz[i]>>agua[i]>>gas[i];
    }
    return n; // retorna n
}

// Encuentra el menor
int encontrarmenor(int agua[], int luz[], int gas[], int n)
{
    int menor = 1e7;

    for (int i = 0; i<n; i++)
    {
        int total = agua[i] + luz[i] + gas[i];

        if (total < menor)
            menor = total;
    }
    return menor; //retorna menor
}

// Calcula el promedio
void promedio(int agua[], int luz[], int gas[], int n, int promedios[])
{
    int promagua = 0, promluz = 0, promgas = 0;
    for (int i = 0; i < n; i++) {
        promagua += agua[i];
        promluz += luz[i];
        promgas += gas[i];
    }
    
    promagua/= n;
    promluz /= n;
    promgas /= n;
    
    promedios[0] = promluz;
    promedios[1] = promagua;
    promedios[2] = promgas;
    
}

// Encuentra # de subsidios
int subsidios(int agua[], int subsidio[], int promedios[], int n) {
    int promsagua = promedios[1];
    int nsubsidios = 0;
    for (int i = 0; i < n; i++) {
        if (agua[i] < promsagua)
        {
            subsidio[i] = i+1;
            nsubsidios++;
        }
    }

   cout<<"casas con subsidio: " << nsubsidios << "\n";

   return nsubsidios; // retorna nsubsidios
}