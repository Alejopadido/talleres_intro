#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r1 = 0, r2 = 0, r3 = 0, personas, grupo = 1, menor, mesas, puestos;
        bool posible = false;
        
        do
        {
            cin >> personas;
            switch(grupo)
            {
                case 1: r1 += personas;
                        menor = r1;
                        break;
                case 2: r2 += personas;
                        if (r2 < menor && r2 != 0) menor = r2;
                        break;
                case 3: r3 += personas;
                        if (r3 < menor && r3 != 0) menor = r3;
                        break;
                default: break;
            }
            grupo++;
            
        } while (personas != 0);
       
        for (puestos = menor; puestos > 1; puestos--)
        {
            if(r1%puestos == 0 && r2%puestos == 0 && r3%puestos == 0)
            {
                cout<<r1/puestos + r2/puestos + r3/puestos<<" mesas de "<<puestos<<" puestos"<<endl;
                posible = true;
                break;
            }
        }
        if (!posible)
            cout<<"Se ubicara una mesa para cada rango de edad.";

    }
}
