/* 
 * File:   Magazyn.h
 * Author: lukasz
 *
 * Created on 12 listopad 2014, 11:55
 */

#ifndef MAGAZYN_H
#define	MAGAZYN_H

class Magazyn {
public:
    static const int MAX_LICZBA_PRODOKTOW = 5;
    static const int MAX_LICZBA_MAGAZYNOW = 5;
    static const int MAX_ILOSC_DANEGO_PRODUKTU = 20;
    static const double ZAKAZANA_WARTOSC_DROGI = 99999.99f; //imitacja nieskończoności
    const int ID(){ return ID;}
    Magazyn(int id, int produkty){
        ID=id;
        liczba_produktow = produkty;
        produkty = new Produkt[liczba_produktow];
    }
    Magazyn(const Magazyn& orig);
    virtual ~Magazyn();
private:
    int ID;
    Produkt* produkty;
    int liczba_produktow;
};

#endif	/* MAGAZYN_H */

