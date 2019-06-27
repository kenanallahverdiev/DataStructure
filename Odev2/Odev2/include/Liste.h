/**
* @file  Liste.h
* @description   bir sayı alıp bunun faktöriyelini buluyor
* @course  1A
* @assignment  Odev2
* @date  09/11/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/


#ifndef LISTE_H
#define LISTE_H
#include <iostream>

class Liste
{                              
    private:
    	int data;
    	int *rakamlar;
    public:
    	Liste(int boyut)
    	{
    		rakamlar=new int[boyut];
		}
		void Ekle(int i,int data)
		{
			rakamlar[i]=data;
		}
	    int getir(int i)
	    {
	    	return rakamlar[i];
		}
		~Liste()
		{
			delete rakamlar;
		}
};



#endif
