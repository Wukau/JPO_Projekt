#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Plansza.h"
#include "Ustawienie_statkow.h"
#include "Strzal.h"
#include "Ruch.h"

using namespace std;

Ustawienie_statkow ustawienie;
Plansza plan;
Strzal strzal;
Ruch ruch;

///Ekran powitalny
void ekran_powitalny();
int read_int();
int A;
int K[7], G[7];

///Ustawienie statkow
void ustawienie_statkow_for();
int ustaw(int n);

///Gra
void gra();
void sterowanie(int kto);
void wypisanie_statkow();
int liczba_na_wspolrzedne(int statki);
void clean();

int main(){
	setlocale(LC_ALL, "polish");
	srand(time(NULL));
	ekran_powitalny();
	A = read_int();
	ustawienie_statkow_for();
	cout << "Statki zostaly ustawione" << endl <<
		"Nacisnij enter aby kontynuwowac";
	getchar(); getchar();
	system("CLS");
	plan.rysuj_plansze();
	gra();

	getchar();
	getchar();
	return 0;
}
void ekran_powitalny(){
	cout <<
		"+==========================================================================+" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|---------------------BITWA-MORSKA---ver-1.01------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|---------------------------------------------Dominik-Rygiel---------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"|--------------------------------------------------------------------------|" << endl <<
		"+==========================================================================+" << endl;
	cout << "WPISZ " << endl <<
		"1. START GRY" << endl <<
		"2. INSTRUKCJA" << endl;
	int x;
	cin >> x;
	if (x == 1) system("CLS");
	if (x == 2){
		cout << "Na poczatku gry gracza ustawia swoje statki na plansze na zmiane z komputerem." << endl <<
			"Moze to zrobic losowo albo wpisywac recznie." << endl <<
			"WA¯NE - statki nie moga sie stykac." << endl <<
			"Po ustawieniu wszystkich statkow zaczyna sie gra." << endl <<
			"Podczas swojej tury Gracz wybiera statek." << endl <<
			"Nastepnie moze (nie musi) przesunac sie nim o 1 pole w wybranym przez niego kierunku" << endl <<
			"Po ruchu nastepuje strzal." << endl <<
			"Gracz wybiera kierunek strzalu (albo wybiera opcje by nie strzelac), a nastepnie losowo generowana" << endl <<
			"jest moc wystrzelonego pocisku (od 1 o 3) mowi ona na jaka odleglosc od statku polecial pocisk" << endl <<
			"Nastepnie przychodzi na ture komputera, ktorego tura wyglada identycznie jak tura gracza" << endl <<
			"Wygrywa ten kto pierwszy zniszczy statki przeciwnika" << endl <<
			"Nacisnij Enter by rozpoczac gre" << endl;
		getchar(); getchar();
		system("CLS");
	}
}
void ustawienie_statkow_for(){
	///Funkcja odpowiadajaca za ustawienie statkow (wszystko opisane w klasie plansza)
	for (int i = 0; i < A; i++){
		K[i] = ustaw(-1);
		cout << "Statek komputera zostal ustawiony na polozeniu " << char(65 + K[i] / 10) << K[i] % 10 << endl;
		plan.rysuj_plansze();
		G[i] = ustaw(0);
		cout << "Statek gracza zostal ustawiony na polozeniu " << char(65 + G[i] / 10) << G[i] % 10 << endl;
		plan.rysuj_plansze();
	}
}
int ustaw(int n){
	///Funkcja sprawdza czy statek ma byc ustawiony losowo czy recznie i odwloluje sie do klasy plan
	int polozenie;
	int losowo = -1;
	if (n == 0){
		cout << "Czy chcesz ustawic statki sam czy losowo" << endl <<
			"-Losowo wpisz 0 i nacisnji enter" << endl <<
			"-Recznie wpisz 1 i nacisnji enter" << endl;

		cin >> losowo;

		if (losowo == 0) losowo = -1;
		else losowo = 1;
	}
	if (losowo == 1) cout << "Ustaw swoj Statek" << endl;
	polozenie = ustawienie.ustawienie_statkow(losowo, n);
	return polozenie;
}

void gra(){
	///Funkcja sprawdza czy ktos wygral i odpowiada za cala interakcje
	int gracz, komputer;
	do{
		sterowanie(0);
		clean();
		gracz = 0;
		komputer = 0;
		for (int i = 0; i < A; i++){
			if (G[i] != -1) gracz++;
			if (K[i] != -1) komputer++;
		}
		if ((gracz == 0) || (komputer == 0)) break;
		sterowanie(-1);
		clean();
		gracz = 0;
		komputer = 0;
		for (int i = 0; i < A; i++){
			if (G[i] != -1) gracz++;
			if (K[i] != -1) komputer++;
		}
		if ((gracz == 0) || (komputer == 0)) break;
	} while (1);
	if (gracz == 0) cout << "Wygral Komputer";
	else cout << "Wygral Gracz";
}
void sterowanie(int kto){
	///Funkcja wybiera czyja kolej jest teraz a nastepnie wykonuje ruch i strzal
	int nowe_wspolrzedne, nr_statku;
	if (kto == 0){
		wypisanie_statkow();
		cin >> nr_statku;
		while (nr_statku<1 || nr_statku>A){
			cout << "Nie masz dostepu do  takiego statku wybierz inny" << endl;
			cin >> nr_statku;
		}
		nr_statku -= 1;
		nowe_wspolrzedne = ruch.ruch(G[nr_statku], 0);
		G[nr_statku] = nowe_wspolrzedne;
		plan.rysuj_plansze();
		strzal.strzal(G[nr_statku], 0);
		plan.rysuj_plansze();
		cout << "Nacisnij enter aby kontynuwowac" << endl;
		getchar();	getchar();
	}
	if (kto == -1){
		do{
			nr_statku = rand() % A;
		} while (K[nr_statku] == -1);
		nowe_wspolrzedne = ruch.ruch(K[nr_statku], -1);
		K[nr_statku] = nowe_wspolrzedne;
		plan.rysuj_plansze();
		cout << "Nacisnij enter aby kontynuwowac" << endl;
		getchar();
		strzal.strzal(K[nr_statku], -1);
		plan.rysuj_plansze();
		cout << "Nacisnij enter aby kontynuwowac" << endl;
		getchar();
	}
}
void wypisanie_statkow(){
	///Funkcja wypisuje dostepne statki gracza
	cout << "Ktorym statkiem chcesz sie poruszyc" << endl;
	for (int i = 0; i < A; i++){
		if (G[i] != -1){
			cout << i + 1 << ".";
			cout << char(liczba_na_wspolrzedne(G[i])) << G[i] % 10 << endl;
		}
	}
}
int liczba_na_wspolrzedne(int statki){
	///Konwertuje pierwsza liczbe wspolrzednych na znak (aby gracz polapal sie w statkach)
	int y = statki / 10;
	return 65 + y;
}
void clean(){
	/// Funkcja (jezeli jakis statek zostal zniszczony czysci plansze i usuwa statki 
	int check_clean;
	check_clean = plan.czyszczenie();
	for (int i = 0; i < A; i++){
		if (G[i] == check_clean) G[i] = -1;
		if (K[i] == check_clean) K[i] = -1;
	}
}


int read_int() {
	int a;
	cout << "Wpisz ile statkow ma byc na planszy (min 1 max 7)";
	cin >> a;
	return a;
}