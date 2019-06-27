/**
* @file  Top.cpp
* @description  top nesneleri aynı yerinde kalacak sadece onları gösteren göstericiler farklı top nesnesini göstererek diziyi ters çeviren program.
* @course  1A
* @assignment  Odev1
* @date  16/10/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "time.h"
#include "windows.h"
#include "Top.h"
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Top::Top()
{

}
Top::Top(char top)
{
	this->top = top;
}
Top::Top(Top *topa, int color)
{
	this->topa = topa;
	this->color = color;
}
char Top::getTop()
{
	return this->top;
}
int Top::getcolor()
{
	return this->color;
}
Top* Top::getTopAdress()
{
	return this->topa;
}
void Top::diziTersCevir(int sayi, Top kecici, Top* pointerler)
{
	for (int i = 0; i < sayi / 2; i++)
	{
		kecici = pointerler[i];
		pointerler[i] = pointerler[(sayi - 1) - i];
		pointerler[(sayi - 1) - i] = kecici;
	}
	cout << "Dizi basariyla ters cevirildi." << endl;
}
void Top::diziYazdir(int sayi, Top* topDizi, Top* pointerler)
{
	cout << "Dizideki Toplar:" << endl;
	for (int i = 0; i < sayi; i++)
	{
		SetConsoleTextAttribute(hConsole, 7);
		cout << "[" << i << "]->";
		SetConsoleTextAttribute(hConsole, pointerler[i].getcolor());
		cout << topDizi[i].getTop() << " " << pointerler[i].getTopAdress() << endl;
		SetConsoleTextAttribute(hConsole, 7);
	}
}
void Top::diziOlustur(int sayi, Top* topDizi, Top* pointerler)
{
	int topKarakter = 1;
	for (int i = 0; i < sayi; i++)
	{
		topDizi[i] = Top(topKarakter);
		pointerler[i] = Top(&topDizi[i], *(getRandom(sayi) + i));
	}
	cout << "Dizi basariyla olusduruldu" << endl;
}

int* Top::getRandom(int sayi)
{
	int* random_dizi = new int[sayi];
	srand(time(0));
	for (int i = 0; i < sayi; i++)
	{
		random_dizi[i] = rand() % 15;
		if (random_dizi[i] == 0)
		{
			random_dizi[i] == 9;
			i--;
		}
		for (int j = 0; j < i; j++)
		{
			if (random_dizi[j] == random_dizi[i])
			{
				i--;
			}
		}

	}
	return random_dizi;
}