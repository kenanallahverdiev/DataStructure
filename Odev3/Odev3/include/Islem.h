/**
* @file  Islem.h
* @description  kullanıcıdan bir klasör yolu istiyor. Daha sonra bu klasörün içinde bulunan sadece *.txt dosyalarını Liste veri yapısına atiyor. Listenin her bir düğümünde bir *.txt dosyası olacaktır. Her dosya bir düğüme atandığı sırada dosyanın içeriği okunuluyor ve kelime kelime ayrılıp ikili arama ağacına bu kelimeler ekleniyor. Her kelime bir düğüme geliyor.
* @course  1A
* @assignment  Odev3
* @date  08/12/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/

#ifndef ISLEM_H
#define ISLEM_H
#include "windows.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "BagilListe.h"
#include "Agac.h"
#define MAX 100
class Islem
{
    public:
    void IlkIs(BagilListe *txtFolders);
    void Lisetele(BagilListe *txtFolders);
    void AramYap(string& kelime,BagilListe *liste);
    };

#endif // ISLEM_H
