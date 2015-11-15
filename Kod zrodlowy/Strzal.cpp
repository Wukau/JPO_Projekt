#include "Strzal.h"
#include "Plansza.h"

using namespace std;

Strzal::Strzal()
{
}


Strzal::~Strzal()
{
}


void Strzal::strzal(int s, int kto){
	///Glowna funkcja odpowiadajaca za strzal statku
	int p;
	if (kto == -1) p = (rand() % 5) * 100 + s;
	else    p = strzal_gracza(s);
	sprawdzenie_strzalu(p);
}
int strzal_gracza(int s){
	Plansza lol;
	///Funkcja wyznaczajaca kierunek strzalu gracza
	int d;
	cout << "Poruszasz " << char(65 + s / 10) << s % 10 << endl;
	cout << "W ktora strone chcesz strzelic: " << endl <<
		"gora - g		dol - d		prawo - p		lewo - l		n - nigdzie" << endl;
	d = wprowadzenie_znaku();
	return  d * 100 + s;
}
void sprawdzenie_strzalu(int p){
	///Funkcja odpowiadajaca za strzal - kierunek i moc (moc jest generowana losowo)
	int d = p / 100,
		x = p % 100 / 10,
		y = p % 10,
		k = rand() % 3 + 1;
	if (d != 4)cout << "Pocik o mocy " << k << " zostal wystrzelony" << " w ";
	if (d == 0) cout << "gore";
	if (d == 1) cout << "dol";
	if (d == 2) cout << "lewo";
	if (d == 3) cout << "prawo";
	if (d == 4) cout << "Pocisk nie zostal wystrzelony";
	cout << endl;
	if (d != 4){
		for (int i = 1; i <= k; i++)
		{
			statki_switch(d, i, x, y);
		}
	}
}
void statki_switch(int d, int i, int x, int y){
	///Funkcja sprawdza czy gracz trafil w jakikolwiek statek (i w przypadku strzalu wychodzacego poza plansze przerywa go)
	switch (d)
	{
	case 0:{
			   if ((plansza[x - i][y] == char(71)) || (plansza[x - i][y] == char(75))){
				   cout << "TRAFIONY ZATOPIONY" << endl;
				   plansza[x - i][y] = 'X';

			   }
			   if (x - i == 0) break;
	}
		break;
	case 1:{
			   if ((plansza[x + i][y] == char(71)) || (plansza[x + i][y] == char(75))){
				   cout << "TRAFIONY ZATOPIONY" << endl;
				   plansza[x + i][y] = 'X';
			   }
			   if (x + i == 9) break;
	}
		break;
	case 2:{
			   if ((plansza[x][y - i] == char(71)) || (plansza[x][y - i] == char(75))){
				   cout << "TRAFIONY ZATOPIONY" << endl;
				   plansza[x][y - i] = 'X';
			   }
			   if (y - i == 0) break;
	}
		break;
	case 3:{
			   if ((plansza[x][y + i] == char(71)) || (plansza[x][y + i] == char(75))){
				   cout << "TRAFIONY ZATOPIONY" << endl;
				   plansza[x][y + i] = 'X';
			   }
			   if (y + i == 9) break;
	}
		break;
	}
}


