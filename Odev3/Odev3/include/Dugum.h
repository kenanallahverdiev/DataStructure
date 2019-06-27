/**
* @file  Dugum.h
* @description  kullanıcıdan bir klasör yolu istiyor. Daha sonra bu klasörün içinde bulunan sadece *.txt dosyalarını Liste veri yapısına atiyor. Listenin her bir düğümünde bir *.txt dosyası olacaktır. Her dosya bir düğüme atandığı sırada dosyanın içeriği okunuluyor ve kelime kelime ayrılıp ikili arama ağacına bu kelimeler ekleniyor. Her kelime bir düğüme geliyor.
* @course  1A
* @assignment  Odev3
* @date  08/12/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/

#ifndef DUGUM_H
#define DUGUM_H
#include "vector"
#include "Agac.h"
#include <stddef.h>
class Dugum
{
public:
    string txtFolder;
    Dugum *next;
    Agac *words;
    Dugum();
    Dugum(string& txtNM,Agac *wrds,string& text);
    void KelimelereAyirma(string& text,Agac *wrds);
};

#endif // DUGUM_H
