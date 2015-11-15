#include <iostream>
#include <string>

class Strzal
{
public:
	Strzal();
	~Strzal();
	void strzal(int s, int kto);
};
///Funkcje ustawienia statkow
int strzal_gracza(int s);
void sprawdzenie_strzalu(int s);
void statki_switch(int d, int i, int x, int y);
///Korzystamy tez z funkcji wprowadzenie_Znaku
