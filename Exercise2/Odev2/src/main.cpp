/**
* @file  Test.cpp
* @description   bir sayı alıp bunun faktöriyelini buluyor
* @course  1A
* @assignment  Odev2
* @date  09/11/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/
#include "Sayi.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int faktorialBulSayi;
	unsigned int zaman = clock();
	cout<<"Sayi:";
	cin>>faktorialBulSayi;
	Sayi *sayi=new Sayi(faktorialBulSayi);
	sayi->faktorial();
	cout << "Hesaplama suresi: " << clock()/1000.0 << endl;
	delete sayi;
	
	return 0;
}