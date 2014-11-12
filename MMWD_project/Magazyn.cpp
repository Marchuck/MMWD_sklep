/* 
 * File:   Magazyn.cpp
 * Author: lukasz
 * 
 * Created on 12 listopad 2014, 11:55
 */

#include "Magazyn.h"

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
    public void UstalLiczbeProdoktow(int produkty){
        liczba_prodoktow=produkty;
    }
    public void UstalIloscProduktu(int produkt, int liczba_jego){
        if(produkt < MAX_LICZBA_PRODOKTOW)
            ilosc_produktu[produkt] = liczba_jego;
    }
    public int ZwrocLiczbeProduktow(){
        return liczba_prodoktow;
    }
    /**
     * 
     * @param indeksProduktu
     * @param cena 
     */
    public void UstalCeneProduktu(int indeksProduktu, float cena){
        if(indeksProduktu<MAX_LICZBA_PRODOKTOW){
            if(indeksProduktu<liczba_prodoktow)
                cena_produktu[indeksProduktu] = cena; 
            else 
                cena_produktu[indeksProduktu] = -1;
        }
    }
    /**
     * @param j - indeks produktu
     * @return ilość j-tego produktu 
     */
    public int ZwrocIloscProduktu(int j){
        return ilosc_produktu[j];
    }
    /**
     * 
     * @param j -indeks produktu
     * @return Cena produktu
     */
    public float ZwrocCeneProduktu(int j){
        return cena_produktu[j];
    }
    public void PobierzIloscProduktu(int indeksporoduktu, int ilosc){
        if(ilosc_produktu[indeksporoduktu] < ilosc){
            zapas_produktow[indeksporoduktu] = ilosc - ilosc_produktu[indeksporoduktu];
            ilosc_produktu[indeksporoduktu] = 0;
        }
        else
            ilosc_produktu[indeksporoduktu] -=ilosc;
    }
    
    public int ZwrocZapasProduktu(int j){
        return zapas_produktow[j];
    }
    /**
     * 
     * @return true jeśli trzeba kontynuować podróż po sklepach,
     *          false jeśli sklep jest już zaopatrzony
     */
    public boolean Zapotrzebowanie(){
        if(ID==0){
        for(int i = 0; i < MAX_LICZBA_PRODOKTOW; i++){
            if(ilosc_produktu[i] > 0)
                return true;
        }
        return false;
        }
        return true;
    }  
    public void UstalDrogiDoInnychMagazynow(float[][] macierz_drog){
        for(int j = 0; j < MAX_LICZBA_MAGAZYNOW;j++){
            if(j==ID)
                droga_do_magazynu[j] = ZakazanaWartoscDrogi;
            else
                droga_do_magazynu[j] = macierz_drog[ID][j];
        }
    }
    /**
     * @param magazyn(indeks jego) 
     * @return droga pomiedzy magazynami
     */
    public float DlugoscPomiedzy(int magazyn){
        return droga_do_magazynu[magazyn];
    }
};