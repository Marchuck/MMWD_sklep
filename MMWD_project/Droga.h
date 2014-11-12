/* 
 * File:   Droga.h
 * Author: lukasz
 *
 * Created on 12 listopad 2014, 12:17
 */

#ifndef DROGA_H
#define	DROGA_H

class Droga {
public:
    Droga(){
        sciezka = new int[1];
        sciezka[0] = 0;//magazyn nr 0

        aktualny_koszt_drogi =0;
    }
    Droga(const Droga& orig);
    virtual ~Droga(){
        delete [] sciezka;
    }
    
    void dodajDoSciezki(int ID_sklepu){
        int dlugosc = dlugoscSciezki();
        if(sciezka[dlugosc-1]!=ID_sklepu){
            int* tmp = sciezka;
            delete [] sciezka;
            sciezka = new int[dlugosc+1];
            for(int i = 0; i < dlugosc; i++)
                sciezka[i] = tmp[i];
            sciezka[dlugosc] = ID_sklepu;
        }
    }
private:
    int dlugoscSciezki(){
        int i = 0;
        while(sciezka[i++])
            ;
        return i;
    }
    int* sciezka;
    double aktualny_koszt_drogi;
    
};

#endif	/* DROGA_H */

