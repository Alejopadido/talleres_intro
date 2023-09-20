// Integrantes: 
// - Alejandro Parrado
// - Sebastian Vargas

#include <iostream>
#include <fstream>

using namespace std; // usamos el nombre de espacio "std"

int revisar(int nSoldados, int nSubordinaciones, int filaindia[], int comandantes[], int subordinados[]) //revisar
{
    int posComandante=0, posSubordinado=0, buenaSubordinacion=0, malaSubordinacion=0, malOrdenComandante=0, malOrdenSubordinado=0;
    for(int i=0; i<nSubordinaciones; i++)
    {
        posComandante=0, posSubordinado=0, buenaSubordinacion=0, malOrdenComandante=0, malOrdenSubordinado=0;
        for(int j=0; j<nSoldados; j++)
        {
            if(comandantes[i]==filaindia[j])
            {
                posComandante=j;
            }
            if(subordinados[i]==filaindia[j])
            {
                posSubordinado=j;
            }
            if(posComandante<posSubordinado)
            buenaSubordinacion++;
            if(posComandante>posSubordinado)
            {
                malOrdenComandante=comandantes[i];
                malOrdenSubordinado=subordinados[i];
            }
        }

    }
    if(buenaSubordinacion==nSubordinaciones-1)
    {
        cout<<"El orden es correcto. "<<endl;
    }
    else if(buenaSubordinacion<nSubordinaciones-1)
    {
        malaSubordinacion=1;
    }
    if(malaSubordinacion==1)
    {
        cout<<"El orden es incorrecto. La pareja mal ordenada es: ";
        cout<<malOrdenComandante<<" - "<<malOrdenSubordinado<<endl;
    }
    // retorna 0
    return 0;
}

int main()
{
    // enteros n, k y l
    int n, k, l;
    ifstream soldados("soldados.txt"); //leer archivo
    soldados>>n;
    for(int i=1; i<=n; i++)
    {
        // numero de soldados
        int nSoldados=0;
        soldados>>nSoldados;
        int filaindia[nSoldados];
        for(k=0; k<nSoldados; k++)
        {
            soldados>>filaindia[k];
        }
        // numero de subordinaciones
        int nSubordinaciones;
        soldados>>nSubordinaciones;
        int comandantes[nSubordinaciones];
        int subordinados[nSubordinaciones];
        for(l=0; l<nSubordinaciones; l++)
        {
            soldados>>comandantes[l];
            soldados>>subordinados[l];
        }

        revisar(nSoldados,nSubordinaciones,filaindia,comandantes,subordinados); //revisar
    }
    return 0;
}
