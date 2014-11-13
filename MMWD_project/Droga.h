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
	static const double ZakazanaWartoscDrogi = 999999.99;
	static const int MaksymalnaIloscIteracji = 20;

    Droga(){
        sciezka = new int[1];
        sciezka[0] = 0;//magazyn nr 0

        aktualny_koszt_drogi =0;
    }
    Droga(const Droga& orig);
    virtual ~Droga(){
        delete [] sciezka;
    }

    void dodaj(int ID_sklepu){
        int dl = dlugosc();
        if(sciezka[dl-1]!=ID_sklepu){
            int* tmp = sciezka;
            delete [] sciezka;
            sciezka = new int[dl+1];
            for(int i = 0; i < dl; i++)
                sciezka[i] = tmp[i];
            sciezka[dl] = ID_sklepu;
        }
    }
    int dlugosc(){
            int i = 0;
            while(sciezka[i++])
                ;
            return i;
    }
    void rysuj(){
    	std::cout << "(";
    	for(int i = 0 ; i < dlugosc();i++)
    		std::cout << sciezka[i]<<", ";
    	std::cout << ")\n";
    }
private:
    int* sciezka;
    double aktualny_koszt_drogi;
};

#endif	/* DROGA_H */

