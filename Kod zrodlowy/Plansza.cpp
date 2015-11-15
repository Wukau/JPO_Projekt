#include "Plansza.h"

using namespace std;

Plansza::Plansza()
{
}

Plansza::~Plansza()
{
}
char plansza[10][10];
int tab[10][10];
void Plansza::rysuj_plansze(){
	///Funkcja rysujaca plansze
	cout << " |";
	for (int i = 0; i < 10; i++){
		cout << i << "|";
	}
	cout << endl;
	for (int i = 0; i < 10; i++){
		cout << char(65 + i) << "|";
		for (int j = 0; j < 10; j++){
			if (plansza[i][j] == NULL)
				cout << char(95) << "|";
			else
				cout << plansza[i][j] << "|";
		}
		cout << endl;
	}
}
int Plansza::czyszczenie(){
	///Funkcja odpowiadajaca za wyczyszczenie planszy tj. jezeli statek zostal zniszony - wymazanie go z mapy i zwrocenie wartosci by dany statek juz sie nie poruszal i nie strzelal
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (plansza[i][j] == 'X'){
				plansza[i][j] = char(95);
				return i * 10 + j;
			}
		}
	}
	return -1;
}