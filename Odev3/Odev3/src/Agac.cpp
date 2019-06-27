/**
* @file  Agac.cpp
* @description  kullanıcıdan bir klasör yolu istiyor. Daha sonra bu klasörün içinde bulunan sadece *.txt dosyalarını Liste veri yapısına atiyor. Listenin her bir düğümünde bir *.txt dosyası olacaktır. Her dosya bir düğüme atandığı sırada dosyanın içeriği okunuluyor ve kelime kelime ayrılıp ikili arama ağacına bu kelimeler ekleniyor. Her kelime bir düğüme geliyor.
* @course  1A
* @assignment  Odev3
* @date  08/12/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/

#include "Agac.h"
Agac::Agac(){
    elemanlar=new string[SIZE];
    Temizle();
}
int Agac::Ara(string& eleman, int suankiIndeks = 0)
{
    while(true)
        {
            if(suankiIndeks == SIZE || IndeksDolulugu[suankiIndeks] == 0) return -1;
            if(elemanlar[suankiIndeks] == eleman && IndeksDolulugu[suankiIndeks] == 1){
                return suankiIndeks;
            }
            else if(eleman < elemanlar[suankiIndeks]) suankiIndeks = 2*suankiIndeks+1;
            else if(eleman > elemanlar[suankiIndeks]) suankiIndeks = 2*suankiIndeks+2;
        }
}
void Agac::Ekle(string& eleman){
    int suankiIndeks = 0;
    while(true){
        if(IndeksDolulugu[suankiIndeks] == 0){
            elemanlar[suankiIndeks]=eleman;
            IndeksDolulugu[suankiIndeks] = 1;
            break;
        }
        else if(eleman < elemanlar[suankiIndeks]) suankiIndeks = 2*suankiIndeks+1;
        else if(eleman > elemanlar[suankiIndeks]) suankiIndeks = 2*suankiIndeks+2;
        else return;
    }
}
bool Agac::Varmi(string& eleman){
    if(Ara(eleman) == -1) return false;
	
    return true;
}
void Agac::Inorder(int suankiIndeks){
 if(IndeksDolulugu[suankiIndeks] != 0 && suankiIndeks < SIZE){
        Inorder(2*suankiIndeks+1);
        cout<<elemanlar[suankiIndeks]<<" ";
        Inorder(2*suankiIndeks+2);
  }
}
void Agac::Temizle(){
    for(int i=0;i<SIZE;i++) IndeksDolulugu[i] = 0;
}
Agac::~Agac(){
    delete [] elemanlar;
};

