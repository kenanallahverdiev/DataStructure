/**
* @file  Islem.cpp
* @description  kullanıcıdan bir klasör yolu istiyor. Daha sonra bu klasörün içinde bulunan sadece *.txt dosyalarını Liste veri yapısına atiyor. Listenin her bir düğümünde bir *.txt dosyası olacaktır. Her dosya bir düğüme atandığı sırada dosyanın içeriği okunuluyor ve kelime kelime ayrılıp ikili arama ağacına bu kelimeler ekleniyor. Her kelime bir düğüme geliyor.
* @course  1A
* @assignment  Odev3
* @date  08/12/2017
* @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
*/

#include "Islem.h"

void Islem::IlkIs(BagilListe *txtFolders)
{
    WIN32_FIND_DATA winFileData;
    HANDLE hFile;
    DWORD dwRet;
    char directoryPath[50];
    char directoryPath1[50];
    char directoryPath2[50];
    string txtName;
    char chTxtName[15];
    string text;
	string tetx1;
    cout<<"Klasor :";
	cin.getline(directoryPath,MAX);
    strcpy(directoryPath1,directoryPath);
	lstrcat(directoryPath,"\\*.txt*");
    hFile = FindFirstFile(directoryPath,&winFileData);
    if (hFile!=INVALID_HANDLE_VALUE)
    {
        do
		{
			strcpy(directoryPath2,directoryPath1);
		    txtName=winFileData.cFileName;
		    lstrcat(directoryPath2,"\\");
			for(int i=0;i<15;i++)
            {
               chTxtName[i]=txtName[i];
            }
		    lstrcat(directoryPath2,chTxtName);
		    ifstream file(directoryPath2);
		    getline(file,text);
            txtFolders->Ekle(txtName,text);
            file.close();
		}
        while (FindNextFile(hFile,&winFileData)!=0);
		FindClose(hFile);
    }
}
void Islem::AramYap(string& kelime,BagilListe *liste)
{
    if(liste->AramaYap(kelime).length()>0){
    cout<<"Aranan kelime "<<liste->AramaYap(kelime)<<" dosyasinin icinde"<<endl;
    }
    else cout<<"Aranan kelime bulunmadi"<<endl;
}
void Islem::Lisetele(BagilListe *txtFolders)
{
    txtFolders->goster();
}

