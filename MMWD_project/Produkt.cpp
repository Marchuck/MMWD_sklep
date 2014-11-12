/* 
 * File:   Produkt.cpp
 * Author: lukasz
 * 
 * Created on 12 listopad 2014, 11:37
 */

#include "Produkt.h"
    /**
     * @return - ilosc faktycznie kupionego produktu
     * @param tyle - ile chcemy kupic produktu
     */
    int Produkt::KupProdukt(int tyle){
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
};

