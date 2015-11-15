#include <iostream>
#include <string>

extern char plansza[10][10];
extern int tab[10][10];
extern int wprowadzenie_znaku();
extern void statek_na_plansze(int x, int y, int n);
class Plansza
{
public:
	Plansza();
	~Plansza();

	void rysuj_plansze();				
	int czyszczenie();			
};

