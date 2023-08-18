/*
    Integrantes:
        - Alejandro Parrado Di Domenico
        - Sebastian Vargas Casquete
*/

#include <iostream>

using namespace std;

int main()
{
    int e1, e2, e3, e4, standard, different;
    string mayorMenor;

    cout<<"Digite 4 valores"<<endl;
    cin>>e1;
    cin>>e2;
    cin>>e3;
    cin>>e4;

    if ((e1 == e2) && (e3 == e4))
    {
        cout<<"Todos los pesos son iguales"<<endl<<endl;
        exit(0);
    }
    else if (e1 == e2)
    {
        standard = e1;
        if (e3 != standard)
            different = e3;
        else if (e4 != standard)
            different = e4;
    }
    else if (e3 == e4)
    {
        standard = e3;
        if (e1 != standard) 
            different = e1;
        else if (e2 != standard) 
            different = e2;
    }
       

    if (different > standard)
        mayorMenor = "Mayor";
    else
        mayorMenor = "Menor";

    cout<<"La esfera "<<different << " es de diferente peso y es " << mayorMenor << " en peso."<<endl<<endl;
}