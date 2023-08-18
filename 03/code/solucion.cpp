#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    int am = 0, bm = 0, cm = 0, n, descuadre_maximo = 0, dia_descuadre_maximo, descuadre_mes = 0;
    const int A = 5000, B = 7500, C = 18000;
    
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a = 0, b = 0, c = 0, dinero_total, valor_tiquetes, descuadre_dia;
        char t;
        cin>>dinero_total;
        
        do
        {
            cin>>t;
            
            switch(t)
            {
                case 'A':
                    a++;
                    break;
                case 'B':
                    b++;
                    break;
                case 'C':
                    c++;
                    break;
                default:
                    break;
            }
        } while (t != 'D');
        
        valor_tiquetes = a*A + b*B + c*C;
        am += a;
        bm += b;
        cm += c;
        
        descuadre_dia = dinero_total - valor_tiquetes;
        descuadre_mes += descuadre_dia;
        if (abs(descuadre_dia) > descuadre_maximo)
        {
            descuadre_maximo = abs(descuadre_dia);
            dia_descuadre_maximo = i + 1;
        }
        
        descuadre_dia == 0 ? cout<<"\nSI"<<endl : cout<<"\nNO $"<<abs(descuadre_dia)<<endl;
    }
    
    cout<<"Total vendido por tipo de paquete: "<<endl;
    cout<<"A $"<<am*A<<endl<<"B $"<<bm*B<<endl<<"C $"<<cm*C<<endl;
    cout<<"Dia de mayor descuadre y valor"<<endl<<dia_descuadre_maximo<<" "<<descuadre_maximo<<endl;
    cout<<"Total de descuadre en el mes"<<endl<<descuadre_mes<<endl;
    float total_mes = am + bm + cm;
    cout<<"Procentaje por tipo de paquete"<<endl;
    cout << "A " << fixed << setprecision(2) << (am * 100 / total_mes) << "%" << endl;
    cout << "B " << fixed << setprecision(2) << (bm * 100 / total_mes) << "%" << endl;
    cout << "C " << fixed << setprecision(2) << (cm * 100 / total_mes) << "%" << endl;
    
}
