
#include <ctime>
#include <cstdlib>
#include<iostream>
#include<string.h>

using std::cout;
using std::string;
using Magazyn::MAX_ILOSC_DANEGO_PRODUKTU;
using Magazyn::MAX_LICZBA_PRODUKTOW;
using Magazyn::MAX_LICZBA_MAGAZYNOW;

#include "Problem_zaopatrzenia.h"

//funkcja służy tylko do tworzenia  losowych odchyleń od wartości
double Problem_zaopatrzenia::Rozbieznosc(double wartosc){
	//TODO: poprawić, użyć lepszych generatorków do robienia odchylenia o podanej wartości promienia
		return (rand()%2==0) ? wartosc: -wartosc;
}
//rysuje macierz dróg w konsoli
void Problem_zaopatrzenia::PokazMacierz(double** Matrix){
	cout<<"\nMacierz Macierz dróg:\n";
    for(int i = 0; i < MAX_LICZBA_MAGAZYNOW; i++){
    	for(int j = 0; j < MAX_LICZBA_MAGAZYNOW; j++){
    		if(i==j)
    			cout<<"####  ";
            else
            	cout<<Matrix[i][j];
        }
        cout<<"\n\n";
    }
}
//tworzy magazyny ustalając drogi między sklepami, ID sklepów, ceny produktów
void Problem_zaopatrzenia::ZrobMagazyny(){
	magazyn = new Magazyn*[Magazyn::MAX_LICZBA_MAGAZYNOW];
    for(int i = 0; i < Magazyn::MAX_LICZBA_MAGAZYNOW;i++){
    	int NowaLiczbaProduktow = rand() % Magazyn::MAX_LICZBA_PRODUKTOW +1;
        double NowaCena = SredniaCena + Rozbieznosc(SredniaCena/3);
    	//w konstruktorze ustalamy ID sklepu, liczbę produktów w sklepie,
    	//oraz wyliczamy drogi pomiędzy sklepami
    	magazyn[i] = new Magazyn(i,NowaLiczbaProduktow,macierz_drog[i]);
        //ustalamy cene każdego rodzaju produktu w każdym magazynie
    	for(int j = 0; j < NowaLiczbaProduktow;j++)
         	magazyn[i]->UstalCeneProduktu(j, NowaCena);
         wektor_odwiedzin[i] = false;
    }
}
//tworzy macierz dróg z pomocą rand()
void Problem_zaopatrzenia::ZrobLosowaMacierzDrog(){
	for(int i = 0; i < Magazyn::MAX_LICZBA_MAGAZYNOW;i++)
		for(int j = 0; j <Magazyn::MAX_LICZBA_MAGAZYNOW;j++){//losujemy długości dróg
			macierz_drog[i][j] = SredniaDroga + Rozbieznosc(SredniaDroga/3);
			macierz_drog[j][i] = macierz_drog[i][j];
			macierz_drog[j][j] = Droga::ZakazanaWartoscDrogi;
		}
}
//zwraca true gdy wszystkie magazyny zostały odwiedzone
bool Problem_zaopatrzenia::WszedzieByles(){
	for(int j = 0; j < Magazyn::MAX_LICZBA_MAGAZYNOW ;j++){
		if(wektor_odwiedzin[j]==false)
				return false;
	}
	return true;
}

void Problem_zaopatrzenia::Start(){
	ZrobLosowaMacierzDrog();
	ZrobMagazyny();
	PokazMacierz(macierz_drog);
	//na początku znajdujemy się w magazynie [0]
	wektor_odwiedzin[0] = true;
	aktualne_id_magazynu = 0;
	Algorytm();
}

void Problem_zaopatrzenia::Algorytm(){
	while(!WszedzieByles() && iteracje < Droga::MaksymalnaIloscIteracji){
		SzukajNajkrotszejDrogi();
	}
	sciezka->rysuj();
}
void Problem_zaopatrzenia::SzukajNajkrotszejDrogi(){
	if(sciezka->dlugosc()==0){
		sciezka->dodaj(0);
	}
	sciezka->dodaj(NastepnyMagazyn());
}
double Problem_zaopatrzenia::MinimumTablicy(double* tablica){
	double min = tablica[0];
	for(int j = 0; j < dlugosc(tablica); j++){
		min = (min > tablica[j]) ? tablica[j] : min;
	}
	return min;
}
//TODO:największy problem z tą funkcją: wybrać drogę do następnego magazynu
int Problem_zaopatrzenia::NastepnyMagazyn(){
	double* drogi_w_otoczeniu = new double[MAX_LICZBA_MAGAZYNOW];
	double** ceny_produktow_w_magazynach = new double*[MAX_LICZBA_MAGAZYNOW];
	int** ilosc_produktow_w_magazynach = new int*[MAX_LICZBA_MAGAZYNOW];

	for(int j = 0 ; j < MAX_LICZBA_MAGAZYNOW;j++){
		ceny_produktow_w_magazynach[j] = new double[MAX_ILOSC_DANEGO_PRODUKTU];
		ilosc_produktow_w_magazynach[j] = new int[MAX_ILOSC_DANEGO_PRODUKTU];

		for(int k = 0 ; k < MAX_ILOSC_DANEGO_PRODUKTU;k++){
			ceny_produktow_w_magazynach[j][k] = magazyn[j]->ZwrocIloscProduktu(k);
			ilosc_produktow_w_magazynach[j][k] = magazyn[j]->ZwrocCeneProduktu(k);
		}
	}

	//na początku w tablicy 'drogi_w_otoczeniu' wpisujemy odległości
	//od poszczególnych magazynów
	for(int j = 0; j < MAX_LICZBA_MAGAZYNOW;j++){
		drogi_w_otoczeniu[j] = magazyn[aktualne_id_magazynu]->DlugoscPomiedzy(j);

	}
	//wyliczamy najkrótszą drogę od aktualnego magazynu
	double najlepsza_droga = MinimumTablicy(drogi_w_otoczeniu);
	//monitorujemy aktualne zapotrzebowanie i wybieramy sklep który chcemy odwiedzić
	int* wektor_zapotrzebowania = new int[1+magazyn[0]->ZwrocLiczbeProduktow()];
	for(int k = 0 ; k < magazyn[0]->ZwrocLiczbeProduktow(); k++){
		wektor_zapotrzebowania[k] = magazyn[0]->ZwrocIloscProduktu(k);
	}
//
//
//
//
//	int LiczbaProduktow = magazyn[aktualne_id_magazynu]->ZwrocLiczbeProduktow();
//	int* produkty = new int[LiczbaProduktow];
//	//zachowuje nr  najblizszego magazynu
//	int IndeksNajlepszejDrogi;
//	//zachowuje indeksy do magazynow z najtanszym produktem
//	int IndeksyNajlepszychMagazynow[] = new int[LiczbaProduktow];
//	//ustalamy wektor najlepszych cen w mieście
//	double DobraCena[] = new double[LiczbaProduktow];
//      for(int i=0; i < Magazyn::MAX_LICZBA_MAGAZYNOW; i++){
//            if(!wektor_odwiedzin[i]);
//                listaDrog.add(magazyn[i].DlugoscPomiedzy(0));
//                tmp.clear();
//                for(int j = 0; j < LiczbaProduktow; j++){
//                    tmp.add(magazyn[i].ZwrocCeneProduktu(j));
//                    Collections.sort(tmp);
//                }
//                listaListCenowych.add(tmp);
//            }
//        }
//        Collections.sort(listaDrog);
   int najlepsze_id;
	++iteracje;
        return aktualne_id_magazynu = magazyn[najlepsze_id]->PobierzID();
}
