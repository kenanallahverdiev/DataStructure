/**
* @file  BagilListe.cpp
* @description  kullanıcıdan bir klasör yolu istiyor. Daha sonra bu klasörün içinde bulunan sadece *.txt dosyalarını Liste veri yapısına atiyor. Listenin her bir düğümünde bir *.txt dosyası olacaktır. Her dosya bir düğüme atandığı sırada dosyanın içeriği okunuluyor ve kelime kelime ayrılıp ikili arama ağacına bu kelimeler ekleniyor. Her kelime bir düğüme geliyor.
* @course  1A
* @assignment  Odev3
* @date  08/12/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/

#include "BagilListe.h"
BagilListe::BagilListe()
{
    basDugum=new Dugum();
	basDugum->next=NULL;
    elemanSayisi=0;
}
string& BagilListe::AramaYap(string& kelime)
{
	string bos="";
	string& bulunmadi=bos;
    iter=basDugum;
    while(iter->next!=NULL)
    {
        if(iter->next->words->Varmi(kelime))
            {
                return iter->next->txtFolder;
            }
        else 
            {
                iter=iter->next;
            }
    }
	return bulunmadi;
}
void BagilListe::Ekle(string& txtName,string& text)
{
    Agac *agac=new Agac();
    iter=basDugum;
    while(iter->next!=NULL)
        {
            iter=iter->next;
        }
    iter->next=new Dugum(txtName,agac,text);
}
void BagilListe::goster()
{
    iter=basDugum;
    while(iter->next!=NULL)
    {
        cout<<iter->next->txtFolder<<":"<<endl;
        iter->next->words->Inorder();cout<<endl;
        iter=iter->next;
    }
}
BagilListe::~BagilListe()
{
    delete basDugum;
    delete iter;
}
