/**
* @file  Top.h
* @description  top nesneleri aynı yerinde kalacak sadece onları gösteren göstericiler farklı top nesnesini göstererek diziyi ters çeviren program.
* @course  1A
* @assignment  Odev1
* @date  16/10/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/

#ifndef TOP_H
#define TOP_H
class Top
{
private:
	Top *topa;
	char top;
	int color;
public:
	Top();
	Top(char top);
	Top(Top *topa, int color);
	char getTop();
	Top* getTopAdress();
	int getcolor();
	void diziTersCevir(int, Top, Top*);
	void diziYazdir(int, Top*, Top*);
	void diziOlustur(int, Top*, Top*);
	int* getRandom(int);
};
#endif // !TOP_H
