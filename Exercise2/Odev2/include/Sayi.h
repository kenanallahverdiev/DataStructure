/**
* @file  Say.h
* @description   bir sayı alıp bunun faktöriyelini buluyor
* @course  1A
* @assignment  Odev2
* @date  09/11/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/
#ifndef SAYI_HPP
#define SAYI_HPP
#include "Liste.h"
#include <iostream>
using namespace std;

#define uzunluk 9999
class Sayi
{
    private:
    	int sayi;
    	Liste *liste;
    public:
    	Sayi(int sayi2)
    	{
    		sayi=sayi2;
    		liste=new Liste(uzunluk);
		}
		
	  
       void faktorial()
       {
       	   
	       liste->Ekle(0,1);
	       int diziUz = 1;
		   cout<<sayi<<"!=";
	       for (int j=2; j<=sayi; j++)
		     diziUz = factorial(j, liste, diziUz);
	
         	for (int i=diziUz-1; i>=0; i--)
		      cout << liste->getir(i);	

        	cout<<endl;
       }

		int factorial(int sayi, Liste *liste, int diziUz)
		{
			int c = 0; 
			for (int i=0; i< diziUz; i++)
			{
				int p = liste->getir(i) * sayi + c;
				int tut = p % 10;
				liste->Ekle(i,tut) ;
				c = p/10;
			}

		while (c)
	    {
		   int tut2 = c%10;
		   liste->Ekle(diziUz,tut2);
		   c = c/10;
		   diziUz++;
    	}
	    return diziUz;
	
		}
		~Sayi()
		{
			
		}
	
};



#endif
