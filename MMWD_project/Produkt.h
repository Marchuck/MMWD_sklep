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
    int KupProdukt(int tyle){
            // 1) kupujemy cały zapas(będziemy jeszcze musieli dokupić produkt)
            if(tyle > ilosc){
                int tmp = ilosc;
                ilosc=0;
                return tmp;
            }
            else{//kupujemy żądaną ilość
                ilosc -= tyle;
                return tyle;
            }
    }
    void ustalCene(double cena){
    	this->cena = cena;
    }
    double Cena(){ return cena;}
    int Ilosc(){   return ilosc;}
private:
    int ilosc;
    double cena;
};

#endif	/* PRODUKT_H */
