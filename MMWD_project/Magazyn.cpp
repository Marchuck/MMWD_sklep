/* 
 * File:   Magazyn.cpp
 * Author: lukasz
 * 
 * Created on 12 listopad 2014, 11:55
 */

#include "Magazyn.h"
#include "Produkt.h"
#include "Droga.h"
Magazyn::Magazyn() {
}

Magazyn::Magazyn(const Magazyn& orig) {
}

Magazyn::~Magazyn() {
}

    //public Produkt[] produkt = new Produkt[MAX_LICZBA_PRODOKTOW];
    
    private int liczba_prodoktow;
    private final int[] ilosc_produktu = new int[MAX_LICZBA_PRODOKTOW];
    private final float[] cena_produktu = new float[MAX_LICZBA_PRODOKTOW];
    private final int[] zapas_produktow = new int[MAX_LICZBA_PRODOKTOW];
    private final float[] droga_do_magazynu = new float[MAX_LICZBA_MAGAZYNOW];
    public Magazyn(int id){
        ID = id;
    }
    

    public int ZwrocZapasProduktu(int j){
        return zapas_produktow[j];
    }

    public void UstalDrogiDoInnychMagazynow(float[][] macierz_drog){
        for(int j = 0; j < MAX_LICZBA_MAGAZYNOW;j++){
            if(j==ID)
                droga_do_magazynu[j] = ZakazanaWartoscDrogi;
            else
                droga_do_magazynu[j] = macierz_drog[ID][j];
        }
    }

};
