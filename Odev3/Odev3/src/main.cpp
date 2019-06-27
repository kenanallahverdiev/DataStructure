/**
* @file  main.cpp
* @description  Kullanıcıdan bir klasör yolu istiyor. Daha sonra bu klasörün içinde bulunan sadece *.txt dosyalarını Liste veri yapısına atiyor. Listenin her bir düğümünde bir *.txt dosyası olacaktır. Her dosya bir düğüme atandığı sırada dosyanın içeriği okunuluyor ve kelime kelime ayrılıp ikili arama ağacına bu kelimeler ekleniyor. Her kelime bir düğüme geliyor.
* @course  1A
* @assignment  Odev3
* @date  08/12/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "Islem.h"
using namespace std;

int main()
{
    string secim;
    string arananSoz;
    Islem *is=new Islem();
    BagilListe *txtFolderNames=new BagilListe();
    is->IlkIs(txtFolderNames);
    do
        {
            cout<<"1.Arama Yap"<<endl<<"2.Listele"<<endl<<"3.Cikis"<<endl;
            cin>>secim;
			if(secim=="1")
            {
				cout<<"Aranan :";cin>>arananSoz;
                is->AramYap(arananSoz,txtFolderNames);
            }
            else if(secim=="2")
            {
                txtFolderNames->goster();
            }
			else
            {
                    if(secim=="3")break;
                cout<<"Hatali giris"<<endl;
            }
        }while(secim!="3");

    delete is,txtFolderNames;
    return 0;
}
