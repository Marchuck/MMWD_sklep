/* 
 * File:   Magazyn.h
 * Author: lukasz
 *
 * Created on 12 listopad 2014, 11:55
 */

#ifndef MAGAZYN_H
#define	MAGAZYN_H
#include "Produkt.h"
#include "Droga.h"



class Magazyn {
public:
    static const int MAX_LICZBA_PRODOKTOW = 5;
    static const int MAX_LICZBA_MAGAZYNOW = 5;
    static const int MAX_ILOSC_DANEGO_PRODUKTU = 20;
    static const double ZAKAZANA_WARTOSC_DROGI = 99999.99f; //imitacja nieskończoności
    static int zapotrzebowanie_na_produkty[MAX_LICZBA_PRODOKTOW];
    const int ID(){ return ID;}
    Magazyn(int id, int rzeczy){
        ID=id;
        liczba_produktow = rzeczy;
        produkty = new Produkt[liczba_produktow];
    }
    Magazyn(const Magazyn& orig);
    void UstalZapotrzebowanie(int* zapotrzebowanie){
    	for(int i = 0; i < MAX_LICZBA_PRODOKTOW;i++)
    		zapotrzebowanie_na_produkty[i] = zapotrzebowanie[i];
    }
    void UstalCeneProduktu(int indeksProduktu, double cena){
    	if(indeksProduktu<liczba_produktow)
    		produkty[indeksProduktu]->UstalCeneProduktu(cena);
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
	void KupProdukt(int indeksPoroduktu, int ilosc){
		int kupiono = produkty[indeksPoroduktu]->KupProdukt(ilosc);

	}


    virtual ~Magazyn();
private:
    int ID;
    Produkt* produkty;
    int liczba_produktow;
};

#endif	/* MAGAZYN_H */

