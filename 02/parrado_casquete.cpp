#include <iostream>

using namespace std;

int
main ()
{
  int years, option = 1, money, sum, c;
  cout <<
    "Ingrese el dinero para calcular la depreciacion y el numero de aC1os (separados por espacio): ";
  cin >> money >> years;
  sum = years * (years + 1) / 2;

  while (option != 0)
    {
      cout << ":  " << " Elija el metodo de depreciacion  :" << endl;
      cout << "1. Linea recta" << endl;
      cout << "2. Suma digito de los aC1os" << endl;
      cout << "3. Salir" << endl;
      cout << "Digite su opcion: ";
      cin >> option;

      switch (option)
	{
	case 1:
	  {
	    for (int j = 1; j <= years; j++)
	      cout << "Año " << j << "      " << money / years << endl;
	    break;

	  }
	case 2:
	  {
	    for (int i = 1; i <= years; i++)
	      {
		c = years - (i - 1);
		cout << "Año " << i << "    " << (money * c) / sum << endl;
	      }
	    break;
	  }
	case 3:
	  option = 0;
	  break;
	case 0:
	  option = 0;
	  break;

	default:
	  cout << "Opcion no valida." << endl;
	  break;
	}

    }
}