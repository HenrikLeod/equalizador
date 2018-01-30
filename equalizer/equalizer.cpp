#include "equalizer.h"
#include <iostream>
#include <fstream>

using namespace std;

void clear_screen();

int main()
{
	system("title ParametricEQ1 CMD");
	system("color 0a");
	equalizer x;
	int select, gain;

	x.build_eq_array();

	do
	{
		x.display_eq();
		cout << "1: Preamp    2: 70 Hz    3: 180 Hz   4: 320 Hz" << endl;
		cout << "5: 600 Hz    6: 1 KHz    7: 3 KHz    8: 6 KHz" << endl;
		cout << "9: 12 KHz   10: 14 Khz  11: 16 KHz   0: Sair" << endl;

		cout << "Qual frequência deseja alterar? ";
		cin >> select;

		if(select != 0)
		{
			cout << "Insira o valor do ganho em dB (entre -6 e 6): ";
			cin >> gain;
			x.set_db((select-1),gain);
			x.build_eq_array();
			
		}
		clear_screen();
		x.file_output();

	}while (select!=0);

	x.file_output();

	cin.get();

	return 0;
}

void clear_screen()
{
	system("cls");
}

void output(equalizer y)
{

}
