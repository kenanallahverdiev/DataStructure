/**
* @file  main.cpp
* @description  top nesneleri aynı yerinde kalacak sadece onları gösteren göstericiler farklı top nesnesini göstererek diziyi ters çeviren program.
* @course  1A
* @assignment  Odev1
* @date  16/10/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "windows.h"
#include "time.h"
#include "Top.h"
using namespace std;

int main()
{
	Top *topDizi;
	Top *pointerler;
	Top kecici;
	int diziBoyutu;
	int secim;
	while (true) {
		system("cls");
		cout << "Dizi Boyutu:"; cin >> diziBoyutu;

		if (diziBoyutu > 0 && diziBoyutu < 15) {
			system("cls");

			topDizi = new Top[diziBoyutu];
			pointerler = new Top[diziBoyutu];

			topDizi->diziOlustur(diziBoyutu, topDizi, pointerler);
			do {
				cout << "1.Diziyi Ters Cevir\n2.Diziyi Yazdir\n3.Cikis\n>>"; cin >> secim;
				if (secim == 1)
				{
					if (diziBoyutu != 1)
					{
						topDizi->diziTersCevir(diziBoyutu, kecici, pointerler);
					}
					else
					{
						cout << "Dizi boyutu 1 oldugu icin,dizi ters cevrilemez" << endl;
					}
				}
				else if (secim == 2)
				{
					topDizi->diziYazdir(diziBoyutu, topDizi, pointerler);
				}
				else if (secim > 3)
				{
					cout << "Hatali Secim" << endl;
					system("pause");
					system("cls");

				}
			} while (secim != 3);
			for (int i = 0; i < diziBoyutu; i++)
			{
				delete[] topDizi, pointerler;
			}
			

			return 0;
		}
		else
		{
			cout << "1-14 araliginda bir deger giriniz" << endl;
			system("pause");
		}
	}
}

