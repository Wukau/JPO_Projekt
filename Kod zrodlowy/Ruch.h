#pragma once
#include <iostream>
#include <string>

class Ruch
{
public:
	Ruch();
	~Ruch();
	int ruch(int w, int kto);	
};

///Funkcje ruchu statkow
int wyznaczamy_d(int x, int y, int kto); 
int wprowadzenie_znaku();
///Korzystamy tez z funkcji statek_na_plansze
