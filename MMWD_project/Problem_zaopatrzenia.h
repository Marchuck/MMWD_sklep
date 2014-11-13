
#include <ctime>
#include <cstdlib>
#include "Magazyn.h"
#include "Produkt.h"
#include<string.h>

#ifndef PROBLEM_ZAOPATRZENIA_H_
#define PROBLEM_ZAOPATRZENIA_H_

class Problem_zaopatrzenia{


private:
	Magazyn** magazyn;
	int aktualne_id_magazynu;
	double** macierz_drog;
	int iteracje;
	bool wektor_odwiedzin[Magazyn::MAX_LICZBA_MAGAZYNOW];
	double SredniaCena;
	double SredniaDroga;
	Droga* sciezka;

	void ZiarnoLosowania(){
		std::srand( time( NULL ) );
	}
public:
	Problem_zaopatrzenia(int liczba_magazynow, double dr, double cen){
		magazyn = new Magazyn[liczba_magazynow];
		SredniaCena = cen;
		SredniaDroga = dr;
		ZiarnoLosowania();
		sciezka = new Droga();
	}
	inline double min(double x,double y){
	        return (x>y) ? y :x;
	}
	double Random01(){
		return (double) (rand()/(RAND_MAX+1.0));
	}
	double Rozbieznosc(double wartosc);
	void PokazMacierz(double** Matrix);
	void ZrobLosowaMacierzDrog();
	void ZrobMacierzDrog(double** macierz);
	int NastepnyMagazyn();
	void ZrobMagazyny();
	bool WszedzieByles();
	//najgłówniejsza funkcja w tej klasie
	void Start();
	void Algorytm();
	void SzukajNajkrotszejDrogi();
	double MinimumTablicy(double* tablica);
	int dlugosc(double* tablica){
		int j = 0;
		while(tablica[j++])
			;
		return j;
	}
};


#endif /* PROBLEM_ZAOPATRZENIA_H_ */
