#include "Produkt.h"
#include "Droga.h"

#ifndef MAGAZYN_H
#define	MAGAZYN_H



class Magazyn {
private:
    int ID;
    Produkt** produkty;
    int liczba_produktow;
    double* droga_do_magazynu;

    int dlugosc(int* wsk){
    	int i = 0;
    	while(wsk[i++])
    		;
    	return i;
    }

public:
    static const int MAX_LICZBA_PRODUKTOW = 5;
    static const int MAX_LICZBA_MAGAZYNOW = 5;
    static const int MAX_ILOSC_DANEGO_PRODUKTU = 20;
    static int zapotrzebowanie_na_produkty[MAX_LICZBA_PRODUKTOW];

    Magazyn(int id, int liczba_produktow, double* wektor_drog){
    	ID=id;
    	droga_do_magazynu = new double[MAX_LICZBA_MAGAZYNOW];
        this->liczba_produktow = liczba_produktow;
        produkty = new Produkt*[liczba_produktow];
        for(int i=0;i<liczba_produktow;i++)
        	produkty[i] = new Produkt();

        for(int i=0;i<MAX_LICZBA_MAGAZYNOW;i++){
        	droga_do_magazynu[i] = wektor_drog[i];
        }
        //"blokujemy" drogę do tego sklepu:
        droga_do_magazynu[ID] = Droga::ZakazanaWartoscDrogi;
    }
    void UstalIloscProduktow(int iloscProduktow){
    	liczba_produktow = iloscProduktow;
    	produkty = new Produkt[liczba_produktow];
    }
    void UstalID(int i){ID = i;}
    int PobierzID() const{
    	return ID;
    }

    void UstalZapotrzebowanie(int* zapotrzebowanie){
    	for(int i = 0; i< dlugosc(zapotrzebowanie) ;i++)
    		zapotrzebowanie_na_produkty[i] = zapotrzebowanie[i];
    }
    bool Zapotrzebowanie(){
    	for(int i = 0; i< dlugosc(zapotrzebowanie_na_produkty) ;i++)
        		if(zapotrzebowanie_na_produkty[i]>0){
        			return true;
        		}
    	return false;
    }

    void UstalCeneProduktu(int indeksProduktu, double cena){
    	if(indeksProduktu<liczba_produktow)
    		produkty[indeksProduktu]->ustalCene(cena);
    }
    void UstalDrogiDoInnychMagazynow(double** macierz_drog){
		for(int j = 0; j < MAX_LICZBA_MAGAZYNOW;j++){
			if(j==ID)
				droga_do_magazynu[j] = Droga::ZakazanaWartoscDrogi;
			else
				droga_do_magazynu[j] = macierz_drog[ID][j];
		}
	}
	int ZwrocLiczbeProduktow(){
            return liczba_produktow;
    }
	double ZwrocCeneProduktu(int indeksProduktu){
		return produkty[indeksProduktu]->Cena();
	}
	double ZwrocIloscProduktu(int indeksProduktu){
		return produkty[indeksProduktu]->Ilosc();

	}
	//TODO: zrobić funkcję
//	void KupProdukt(int indeksPoroduktu, int ilosc){
//		int kupiono = produkty[indeksPoroduktu].KupProdukt(ilosc);
//	}
	double DlugoscPomiedzy(int magazyn){
	        return droga_do_magazynu[magazyn];
	    }

    virtual ~Magazyn(){
    	delete [] droga_do_magazynu;
    	delete[] produkty;
    }

};
