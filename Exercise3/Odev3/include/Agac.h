/**
* @file  Agac.h
* @description  kullanıcıdan bir klasör yolu istiyor. Daha sonra bu klasörün içinde bulunan sadece *.txt dosyalarını Liste veri yapısına atiyor. Listenin her bir düğümünde bir *.txt dosyası olacaktır. Her dosya bir düğüme atandığı sırada dosyanın içeriği okunuluyor ve kelime kelime ayrılıp ikili arama ağacına bu kelimeler ekleniyor. Her kelime bir düğüme geliyor.
* @course  1A
* @assignment  Odev3
* @date  08/12/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/

#ifndef AGAC_H
#define AGAC_H
#include <string>
#include <iostream>
#include <cmath>
#define SIZE 10000
using namespace std;

class Agac{
	private:
        string *elemanlar;
		int IndeksDolulugu[SIZE];
	public:
		Agac();
		void kelimeyiYazdir();
        int Ara(string&, int);
		void Ekle(string&);
		bool Varmi(string&);
		void Inorder(int suankiIndeks=0);
		void Temizle();
		~Agac();
};

#endif // AGACDIZI_H
