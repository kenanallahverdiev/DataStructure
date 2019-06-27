/**
 * @file  Dugum.hpp
 * @description Huffman Ağacı oluşturup karakterlerin bit karşılık tablosu ve kelimelerin bit karşılıklarını oluşturmaldır. Daha sonra deneme.txt dosyasında bulunan kelimelerin hepsinin Huffman ağacından faydalanarak bit karşılığını yeni bir dosyaya (“Bit.dat”) yazılmaldır. Burada dikkat edilmesi gereken bitlerin Bit.dat dosyasına direk bit şeklinde yazılmasıdır (Karakter türünde yazılmamalıdır). Hangi karakterin hangi bite karşılık geldiğini de ayrıca Tablo.txt dosyasına text olarak yazılacaktır. Program kapatılıp tekrar açıldığında Tablo.txt dosyasındaki tablo yardımıyla Bit.dat dosyası açılıp dosyadan bitler okunup ekrana karakter karşılıkları yazılacaktır.
 * @course  1A
 * @assignment  Odev4
 * @date  21/12/2017
 * @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
 */
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
#include <fstream>
using namespace std;

class Dugum{
public:
    char karakter;
    int frekans;	// Dosyada kaÁ kez tekrarland˝˝
    string kod; 	// 01 kod kar˛˝l˝˝
    Dugum* sol;
    Dugum* sag;
    Dugum(char kr,int frek, Dugum* sl=NULL,Dugum *sg=NULL);
    bool Yaprakmi() const;
    bool operator==(Dugum&);
    bool operator!=(Dugum&);
    bool operator>(Dugum&);
};


#endif
