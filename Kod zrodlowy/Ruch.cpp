#include "Ruch.h"
#include "Plansza.h"

using namespace std;

Ruch::Ruch()
{
}


Ruch::~Ruch()
{
}

int Ruch::ruch(int w, int kto){
	///Glowna funkcja odpowiadajaca za ruch statku
	int d, x, y, f;
	x = w / 10;
	y = w % 10;
	f = w;
	plansza[x][y] = char(95); ///W miejscu przed ruchem statku ustawia pauze "_" (wolne pole)
	d = wyznaczamy_d(x, y, kto);
	switch (d){
	case 0:
	{
			  if ((x == 0) || (plansza[x - 1][y] == char(71)) || (plansza[x - 1][y] == char(75))){
				  if (kto == 0)  cout << "Nie mozesz sie poruszyc w ta strone" << endl;
				  break;
			  }
			  x = x - 1;
	}
		break;
	case 1:
	{
			  if ((x == 9) || (plansza[x + 1][y] == char(71)) || (plansza[x + 1][y] == char(75))){
				  break;
			  }
			  x = x + 1;
	}
		break;
	case 2:
	{
			  if ((y == 0) || (plansza[x][y - 1] == char(71)) || (plansza[x][y - 1] == char(75))){
				  break;
			  }
			  y = y - 1;
	}
		break;
	case 3:
	{
			  if ((y == 9) || (plansza[x][y + 1] == char(71)) || (plansza[x][y + 1] == char(75))){
				  break;
			  }
			  y = y + 1;
	}
		break;
	case 4:
		break;
	}
	statek_na_plansze(x, y, kto);
	if (kto == 0)
		cout << "Statek gracza z polozenia " << char(65 + f / 10) << f % 10 << " poruszyl sie na polozenie " << char(65 + x) << y << endl;
	if ((kto == -1) && (x >= 0) && (x <= 9) && (y >= 0) && (y <= 9))
		cout << "Statek komputera z polozenia " << char(65 + f / 10) << f % 10 << " poruszyl sie na polozenie " << char(65 + x) << y << endl;
	return x * 10 + y;
}
int wyznaczamy_d(int x, int y, int kto){
	///Funkcja wyznaczajaca kierunek ruchu
	if (kto == -1) return rand() % 5;
	else if (kto == 0){
		cout << "Poruszasz statkiem ktory jest na polozeniu " << char(65 + x) << y << endl <<
			"W ktora strone chcesz sie poruszyc" << endl <<
			"gora - g      dol - d               prawo - p       lewo - l         n - nigdzie" << endl;
		return	wprowadzenie_znaku();
	}
	return 0;
}
int wprowadzenie_znaku(){
	///Funkcja konwertujaca wybor kierunku ruchu/strzaly na liczbe (ktora wprowadzam do switcha)
	///Funkcja istnieje poniewaz komputer losuje kierunek i latwiej jest przekonwertowac litere na liczbe niz losowa liczbe na litere
	char znak_strzalu;
	bool strzal_tf = false;
	while (strzal_tf == false){
		cin >> znak_strzalu;
		strzal_tf = true;
		if (znak_strzalu >= 100 && znak_strzalu <= 112) znak_strzalu = znak_strzalu - 32;
		if (znak_strzalu == 'G') return 0;
		if (znak_strzalu == 'D') return 1;
		if (znak_strzalu == 'L') return 2;
		if (znak_strzalu == 'P') return 3;
		if (znak_strzalu == 'N') return 4;
		else{
			strzal_tf = false;
			cout << "Podales zly znak - podaj prawidlowy" << endl <<
				"gora - g      dol - d               prawo - p       lewo - l         n - nigdzie" << endl;
		}
	}
}