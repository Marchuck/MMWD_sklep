

#include <iostream>
#include<Magazyn.h>
#include<Produkt.h>
#include<Droga.h>
#include"Problem_zaopatrzenia.h"
using namespace std;

int main() {
//	Problem_zaopatrzenia(liczba_magazynów, średnia_długość_drogi, średnia_cena_produktu)
	Problem_zaopatrzenia *problem = new Problem_zaopatrzenia(5,30,20);
	problem->Start();
	return 0;
}
