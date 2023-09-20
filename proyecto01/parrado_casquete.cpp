// Cien Anos de Soñedad
#include <iostream>
#include <fstream>

using namespace std;

const string Nombre_De_La_Libreria = "Libros y Algo Mas";
const int MAX_LIBROS = 50;
const int PROPIEDADES_POR_LIBRO = 10;
const int PROPIEDADES_CONTADURIA = 2;

void MostrarNombreDeLaLibreriaYMenuDeOpciones();
void ObtenerInformacionDelLibro(string libros[][PROPIEDADES_POR_LIBRO], int cantidadLibros);
int LeerArchivo(string libros[][PROPIEDADES_POR_LIBRO]);
string ObtenerInformacionEspecificaDelLibroIndicadoPorElUsuarioMedianteLaConsola(string libros[][PROPIEDADES_POR_LIBRO], int NumeroDelLibro, int Propiedad);
void imprimirElInventarioCompletoDeLibros(string libros[][PROPIEDADES_POR_LIBRO], int cantidadLibros);
float calcularVentasTotales(float contaduria[][PROPIEDADES_CONTADURIA], int numeroLibro);
void leerDatosNumericosDelArchivoParaObtenerPrecioYVentas(float contaduria[][2]);

int main() {
    string libros[MAX_LIBROS][PROPIEDADES_POR_LIBRO];
    float contaduria[MAX_LIBROS][PROPIEDADES_CONTADURIA];
    int cantidadLibros = LeerArchivo(libros);
    int opcion;
    MostrarNombreDeLaLibreriaYMenuDeOpciones();
    cout << "\n" << ": ";
    cin >> opcion;

    // Accion en base la opcion
    switch (opcion)
    {
    case 1:
        // vender
        break;
    case 2:
        // obtener listadod de inv
        imprimirElInventarioCompletoDeLibros(libros, cantidadLibros);
        break;
    case 3:
        // Info de un libro
        ObtenerInformacionDelLibro(libros, cantidadLibros);
        break;
    case 4:
        // mostrar informa diario
        int uwu;
        cout << "De que libro desea la informacion?: ";
        cin >> uwu;
        uwu--;
        leerDatosNumericosDelArchivoParaObtenerPrecioYVentas(contaduria);
        calcularVentasTotales(contaduria, uwu);
        break;
    case 5:
        // recibir una remesa de libros
        break;
    case 0:
        // salir
        break;
    default:
        break;
    }
}

// Muestra el nombre de la libreria y el menu de opciones
void MostrarNombreDeLaLibreriaYMenuDeOpciones(){
    cout<<"Bienvenido a " << Nombre_De_La_Libreria << ", Digite una opcion: " << "\n"
    <<"1. Vender un libro" << "\n"
     << "2. Obtener un listado del inventario completo" << "\n"
      << "3. Obtener informacion del inventario para un unico titulo" << "\n"
       << "4. Mostrar un informe diario" << "\n" 
       << "5. Recibir una remesa de libros" << "\n" 
       << "0. Salir del sistema de control de inventario :(";
}

void ObtenerInformacionDelLibro(string libros[][PROPIEDADES_POR_LIBRO], int cantidadLibros) {
    int numeroDeLibro;
    cout << "Ingrese el numero del libro: ";
    cin >> numeroDeLibro;
    numeroDeLibro--;

    if (numeroDeLibro >= 0 && numeroDeLibro < cantidadLibros) {
        for (int j = 0; j < PROPIEDADES_POR_LIBRO; j++) {
            switch (j)
            {
            case 0:
                cout<<"Titulo: ";
                break;
            case 1:
                cout<<"Apellido del Autor: ";
                break;
            case 2:
                cout<<"Nombre del Autor: ";
                break;
            case 3:
                cout<<"Precio: ";
                break;
            case 4:
                cout<<"Editorial: ";
                break;
            case 5:
                cout<<"ISBN: ";
                break;
            case 6:
                cout<<"Fecha de Copyright: ";
                break;
            case 7:
                cout<<"Ejemplares: ";
                break;
            case 8:
                cout<<"Estado: ";
                break;
            case 9:
                cout<<"Ejemplares vendidos: ";
                break;
            default:
                break;
            }

           //cout << libros[numeroDeLibro][j] << "\n";
           cout << ObtenerInformacionEspecificaDelLibroIndicadoPorElUsuarioMedianteLaConsola(libros, numeroDeLibro, j) << "\n";
        }
        cout << endl;
    } else {
        cout << "Numero de libro no valido." << endl;
    }
}

void imprimirElInventarioCompletoDeLibros(string libros[][PROPIEDADES_POR_LIBRO], int cantidadLibros) {
    for (int i = 0; i < cantidadLibros; i++){
        for (int j = 0; j < PROPIEDADES_POR_LIBRO; j++){
                switch (j)
                {
                    case 0:
                        cout<<"Titulo: ";
                        break;
                    case 1:
                        cout<<"Apellido del Autor: ";
                        break;
                    case 2:
                        cout<<"Nombre del Autor: ";
                        break;
                    case 3:
                        cout<<"Precio: ";
                        break;
                    case 4:
                        cout<<"Editorial: ";
                        break;
                    case 5:
                        cout<<"ISBN: ";
                        break;
                    case 6:
                        cout<<"Fecha de Copyright: ";
                        break;
                    case 7:
                        cout<<"Ejemplares: ";
                        break;
                    case 8:
                        cout<<"Estado: ";
                        break;
                    case 9:
                        cout<<"Ejemplares vendidos: ";
                        break;
                    default:
                        break;
                }

                cout << libros[i][j] << "\n";
        }
    }
}

string ObtenerInformacionEspecificaDelLibroIndicadoPorElUsuarioMedianteLaConsola(string libros[][PROPIEDADES_POR_LIBRO], int NumeroDelLibro, int Propiedad) {
    return libros[NumeroDelLibro][Propiedad];
}

int LeerArchivo(string libros[][PROPIEDADES_POR_LIBRO]) {
    int cantidadLibros2;
    ifstream entrada("inBooks.txt");

    if (!entrada) {
        cout << "Archivo no encontrado." << endl;
        exit(1);
    }

    entrada >> cantidadLibros2;

    for (int i = 0; i <= cantidadLibros2; i++) {
        for (int j = 0; j < PROPIEDADES_POR_LIBRO; j++) {
            entrada >> libros[i][j];
        }
    }

    entrada.close();

    return cantidadLibros2;
}

float calcularVentasTotales(float contaduria[][PROPIEDADES_CONTADURIA], int numeroLibro){
    cout <<" PRECIO LIBRO " << contaduria[numeroLibro][0];
    cout <<" EJEMPLARES VENDIDOS " << contaduria[numeroLibro][1];
    // return 0;
    return 0;
}

void leerDatosNumericosDelArchivoParaObtenerPrecioYVentas(float contaduria[][PROPIEDADES_CONTADURIA]){

    int cantidadLibros3;
    ifstream entrada2("inBooks.txt");

    if(!entrada2) {
        cout << "No se encontro el re malparido catre dodecaedro setenta octa peyondorrea triplehijueputa archivo" << endl;
        exit(1);
    }

    entrada2 >> cantidadLibros3;

    for (int i = 0; i < cantidadLibros3; i++) {
        for (int j = 0; j < PROPIEDADES_POR_LIBRO; j++) {
            string amogus;
            entrada2 >> amogus;
           // cout<<amogus;
            if (j == 2) {
               //contaduria[i][0] = amogus;
               
               // amogus >> contaduria[i][0];
            } else if (j == 9) {
                //contaduria[i][1] = amogus;
               // amogus >> contaduria[i][1];
               
            }
            
        }
    }

    entrada2.close();
}