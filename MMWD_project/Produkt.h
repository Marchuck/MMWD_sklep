/* 
 * File:   Produkt.h
 * Author: lukasz
 *
 * Created on 12 listopad 2014, 11:37
 */

#ifndef PRODUKT_H
#define	PRODUKT_H

class Produkt {
public:
    Produkt(const Produkt& orig) {
        this->cena = orig.cena;
        this->ilosc = orig.ilosc;
    }
    Produkt(double cena, int ilosc){
        this->cena = cena;
        this->ilosc = ilosc;
    }
    virtual ~Produkt(){}
    int KupProdukt(int ID_produktu, double tyle);
private:
    int ilosc;
    double cena;
};

#endif	/* PRODUKT_H */