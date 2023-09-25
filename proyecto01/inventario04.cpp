// Integrantes:
// - Alejandro Parrado
// - Sebastian Vargas Casquete

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_LIBROS = 50;
const int PROPIEDADES_POR_LIBRO = 4;

// Declaracion de funciones
int leerDatosDeEntradaDelArchivoTxt(int libros[][PROPIEDADES_POR_LIBRO]);
int sell(int libros[][PROPIEDADES_POR_LIBRO], int numLibro, int numLibros);
void guardarCambios(int libros[][PROPIEDADES_POR_LIBRO], int numLibros);
void list_one(int numLibro, int precio, int cantidadInv);
void menu(int libros[][PROPIEDADES_POR_LIBRO], int numLibros);

// es la funcion main
int main() {
    int libros[MAX_LIBROS][PROPIEDADES_POR_LIBRO];
    int numLibros = leerDatosDeEntradaDelArchivoTxt(libros);

    menu(libros, numLibros);

   // sell(libros, 3, numLibros);
}

//Es la funcion leerDatosDeEntradaDelArchivoTxt
int leerDatosDeEntradaDelArchivoTxt(int libros[][PROPIEDADES_POR_LIBRO]) {
    int cantidadLibros;
    ifstream entrada("inBooks.txt");
    if (!entrada)
    {
        cout<<"No se encontro el re malparido catre dodecaedro setenta peyondorrea archivo";
        exit(1);
    }

    entrada >> cantidadLibros;

    for (int i = 0; i < cantidadLibros; i++) {
        for (int j = 0; j < PROPIEDADES_POR_LIBRO; j++) {
            entrada >> libros[i][j];
        }
        list_one(i, libros[i][1], libros[i][2]);
    }

    return cantidadLibros;
}

// funcion sell
int sell(int libros[][PROPIEDADES_POR_LIBRO], int numLibro, int numLibros) {
    numLibro--;
    int librosSolicitados;
    cout << "Cuantos libros desea comprar?: ";
    cin >> librosSolicitados;


    if (librosSolicitados <= libros[numLibro][2]){
        cout<< librosSolicitados << " libros vendidos" << "\n";
        libros[numLibro][2] -= librosSolicitados;
    }else{
        cout << "No es posible hacer la venta" << "\n" << "Para el libro " << numLibro << " se solicitaron " << librosSolicitados << ", pero solo hay " << libros[numLibro][2] << " disponibles" << "\n";
    }

    guardarCambios(libros, numLibros);
}

void guardarCambios(int libros[][PROPIEDADES_POR_LIBRO], int numLibros){
    ofstream salida("outBooks.txt");
    if (!salida.is_open()) {
        cout << "No se pudo crear el puto archivo";
        exit(1);
    }

    for (int i = 0; i < numLibros; i++) {
        for (int j = 0; j < PROPIEDADES_POR_LIBRO; j++) {
            salida << libros[i][j] << " ";
        }
        salida << "\n";
    }
}

void list_one(int numLibro, int precio, int cantidadInv)
{
    cout<<"Libro: " << numLibro << "\n"<<
    "Precio: " << precio << "\n"<<
    "Cantidad en el Inventario: " << cantidadInv << "\n";
}

void menu(int libros[][PROPIEDADES_POR_LIBRO], int numLibros){
   bool salio = false;
   while (!salio)
   {
     cout << "\n" <<
    "L: Listar toda la información del inventario" << "\n" <<
    "D: Introduce una remesa de libros en el inventario" << "\n" <<
    "R: Genera un informe diario de ventas" << "\n" <<
    "S: vender un libro" << "\n" <<
    "Q: Salir del Programa" << "\n"
    <<"Inserte un comando: ";
    char opcion;
    cin >> opcion;

    switch (opcion)
    {
    case 'L':
        cout<<"se ha entrado en la funcion list_all";
        break;
    case 'D':
        cout<<"se ha entrado en la funcion de Remesa";
        break;
    case 'R':
        cout<<"se ha entrado en la funcion generar_informe_de_ventas";
        break;
    case 'S':
        cout<<"se ha entrado en la funcion Sell, Inserte el numero del libro: ";
        int nlib;
        cin>>nlib;
        nlib--;
        sell(libros, nlib, numLibros);
        salio = true;
        break;   
    case 'Q':
        cout<<"saliendo del programa";
        salio = true;
        break;
    default:
        cout<<"Opcion invalida";
        break;
    }
   }
   
}