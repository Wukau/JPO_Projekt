#include <iostream>
#include <string>
class Ustawienie_statkow
{
public:
	Ustawienie_statkow();
	~Ustawienie_statkow();
	int ustawienie_statkow(int w, int n);

};



int ustawienie_losowe();
int ustawienie_reczne();
bool sprawdzenie_polozenia(int w);
int wprowadzanie_danych();
bool sprawdzenie_znakow(char znak, int y);
void statek_na_plansze(int x, int y, int n);
void tab_minus_statek(int x, int y);
