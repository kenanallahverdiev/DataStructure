/**
* @file  Dugum.cpp
* @description  kullanıcıdan bir klasör yolu istiyor. Daha sonra bu klasörün içinde bulunan sadece *.txt dosyalarını Liste veri yapısına atiyor. Listenin her bir düğümünde bir *.txt dosyası olacaktır. Her dosya bir düğüme atandığı sırada dosyanın içeriği okunuluyor ve kelime kelime ayrılıp ikili arama ağacına bu kelimeler ekleniyor. Her kelime bir düğüme geliyor.
* @course  1A
* @assignment  Odev3
* @date  08/12/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/

#include "Dugum.h"

Dugum::Dugum(string& txtNM,Agac *wrds,string& text)
{
        txtFolder=txtNM;
        next=NULL;
        words=wrds;
        KelimelereAyirma(text,words);
}
Dugum::Dugum()
{

}
void Dugum::KelimelereAyirma(string& text,Agac *wrds)
{
    string kelime;
    vector<string> arr;
    string delim(" ");
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    while( ( next = text.find( delim, prev ) ) != string::npos ){
    string tmp = text.substr( prev, next-prev );
    wrds->Ekle(tmp);
    arr.push_back( text.substr( prev, next-prev ) );
    prev = next + delta;
    }
    string tmp = text.substr( prev );
    wrds->Ekle(tmp);
    arr.push_back( text.substr( prev ) );
}

