/**
* @file  BagilListe.h
* @description  kullanıcıdan bir klasör yolu istiyor. Daha sonra bu klasörün içinde bulunan sadece *.txt dosyalarını Liste veri yapısına atiyor. Listenin her bir düğümünde bir *.txt dosyası olacaktır. Her dosya bir düğüme atandığı sırada dosyanın içeriği okunuluyor ve kelime kelime ayrılıp ikili arama ağacına bu kelimeler ekleniyor. Her kelime bir düğüme geliyor.
* @course  1A
* @assignment  Odev3
* @date  08/12/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/

#ifndef BAGILLISTE_H
#define BAGILLISTE_H
#include "Agac.h"
#include "Dugum.h"
class BagilListe
{
private:
    Dugum *basDugum;
    Dugum *iter;
    int elemanSayisi;
public:
    BagilListe();
    void goster();
    void Ekle(string& txtName,string& text);
    string& AramaYap(string& kelime);
    ~BagilListe();
};

#endif // BAGILLISTE_H
