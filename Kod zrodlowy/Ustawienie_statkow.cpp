#include "Ustawienie_statkow.h"
#include "Plansza.h"

using namespace std;

Ustawienie_statkow::Ustawienie_statkow()
{
}


Ustawienie_statkow::~Ustawienie_statkow()
{
}
int Ustawienie_statkow::ustawienie_statkow(int w, int n){
	///Glowna funkcja odpowiadajaca za ustawienie statku
	if (w == -1) w = ustawienie_losowe();
	else w = ustawienie_reczne();
	int	x = w % 100 / 10,
		y = w % 10;
	statek_na_plansze(x, y, n);
	tab_minus_statek(x, y);
	return w;
}
int ustawienie_losowe(){
	///Wywolanie tej funkcji powoduje, ze statek bedzie ustawiony losowo (domyslna funkcja dla komputera)
	int w;
	do{
		w = rand() % 100;
	} while (sprawdzenie_polozenia(w) == false);
	return w;
}
int ustawienie_reczne(){
	///Wywolanie tej funkcji powoduje, ze statek bedzie ustawiony recznie przez gracza
	cout << "Podaj wspolrzedne (litera/liczba) ";
	int w;
	w = wprowadzanie_danych();
	while (sprawdzenie_polozenia(w) == false){
		cout << "Polozenie statku jest nieprawidlowe" << endl <<
			"-Statki sie stykaja" << endl <<
			"-Statki nakladaja sie na siebie" << endl <<
			"-Statek wychodzi poza plansze" << endl <<
			"-Dane zostaly zle wpisane" << endl <<
			"Podaj inne wspolrzedne: ";
		w = wprowadzanie_danych();
	}
	return w;
}
bool sprawdzenie_polozenia(int w){
	///Funkcja sprawdza czy statek moze byc polozony w danej pozycji (wybranej przez gracza lub losowej) tj. czy nie styka sie z innymi statkami
	int	x = w / 10,
		y = w % 10;
	if (tab[x][y] == -1)    return false;
	return true;
}
int wprowadzanie_danych(){
	/// Funkcja do ktorej zostana wprowadzone dane nt. ustawienia statkow (w przypadku ustawienia recznego) i zwracajaca skonwerotowana pozyje
	int x, y;
	char znak;
	cin >> znak;
	if (znak >= 97 && znak <= 106) znak = znak - 32;
	x = znak - 65;
	cin >> y;
	while (sprawdzenie_znakow(znak, y) == false){
		cout << "Podane znaki sa nieparwidlowe: " << endl << "Wprowadz poprawne";
		cin >> znak;
		if (znak >= 97 && znak <= 106) znak = znak - 32;
		x = znak - 65;
		cin >> y;
	}
	return x * 10 + y;
}
bool sprawdzenie_znakow(char znak, int y){
	///Funkcja sprawdza czy podany przez znak - pierwsza wspolrzedna statku (wybiera od A do J) - istnieje
	if ((znak <= 106) && (znak >= 97) || (znak <= 74) && (znak >= 65)){
		if ((y >= 0) && (y <= 9)){
			return true;
		}
	}
	return false;
}
void statek_na_plansze(int x, int y, int n){
	///Funkcja ustawiajaca wstawiajaca statek na plansze
	if (n == -1) plansza[x][y] = char(75);
	else plansza[x][y] = char(71);
}
void tab_minus_statek(int x, int y){
	///Funkcja ktora wstawia -1 w miejscu styku statku (dzieki temu inne statki nie beda mogly zostac tu ustawione i nie beda sie stykac)
	for (int i = x - 1; i <= x + 1; i++){
		for (int j = y - 1; j <= y + 1; j++){
			if (i < 0) i = 0;
			if (j < 0) j = 0;
			tab[i][j] = -1;
		}
	}
}