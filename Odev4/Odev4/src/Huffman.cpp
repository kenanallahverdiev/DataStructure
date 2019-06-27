/**
 * @file  Huffman.cpp
 * @description Huffman Ağacı oluşturup karakterlerin bit karşılık tablosu ve kelimelerin bit karşılıklarını oluşturmaldır. Daha sonra deneme.txt dosyasında bulunan kelimelerin hepsinin Huffman ağacından faydalanarak bit karşılığını yeni bir dosyaya (“Bit.dat”) yazılmaldır. Burada dikkat edilmesi gereken bitlerin Bit.dat dosyasına direk bit şeklinde yazılmasıdır (Karakter türünde yazılmamalıdır). Hangi karakterin hangi bite karşılık geldiğini de ayrıca Tablo.txt dosyasına text olarak yazılacaktır. Program kapatılıp tekrar açıldığında Tablo.txt dosyasındaki tablo yardımıyla Bit.dat dosyası açılıp dosyadan bitler okunup ekrana karakter karşılıkları yazılacaktır.
 * @course  1A
 * @assignment  Odev4
 * @date  21/12/2017
 * @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
 */
#include "Huffman.hpp"
Huffman::Huffman(string dosyaYolu)throw(string)
{
	harfler = 256;
	girdi="";
	try{
		DosyaOku(dosyaYolu);
	}
	catch(string ex){
		throw ex;
	}
	root=NULL;
}
void Huffman::DosyaOku(string dosyaYolu)throw(string){
	string satir;
	ifstream dosya(dosyaYolu.c_str());
	if (dosya.is_open())
	{
		while (getline(dosya,satir))
		{ 	
			girdi+=satir;
			girdi+='\n';
		}
		dosya.close();
	}
	else throw "Dosya acilamadi"; 
}
void Huffman::Kodla(int secim){
	char karakterler[girdi.size()-1];
	
	strcpy(karakterler, girdi.c_str());
	
	int frek[harfler]; 
	for(int i=0;i<harfler;i++)frek[i] = 0;
	
	for (int i = 0; i < girdi.size()-1; i++)
		frek[karakterler[i]]++;
	
	root = AgacOlustur(frek);
	
	KodOlustur(root, "");
	if(secim==1)
	{
		kodlayici(root);
	}
	else
	{
		//kodCozucu();
	}
	dosya.close();
	dosyaBit.close();
}	
Dugum* Huffman::AgacOlustur(int frek[])
{
	Dugum* dugumler[harfler];
	for(int i=0;i<harfler;i++)
	{
		if(frek[i]>0)
		{
			if(i==32) dugumler[i]=new Dugum('@',frek[i]);
			
			else if(i==10) dugumler[i]=new Dugum('<',frek[i]);
			
			else dugumler[i] = new Dugum((char)i,frek[i]);
		}
		else{
			dugumler[i] = NULL;
		}
	}
	while(true)
	{
		int ilkIndeks = MinDugumIndeks(dugumler);				
		Dugum *min1 = dugumler[ilkIndeks];
		dugumler[ilkIndeks] = NULL;
		int ikinciIndeks = MinDugumIndeks(dugumler);
		if(ikinciIndeks == -1)
		{
			return min1;
		}
		Dugum *min2 = dugumler[ikinciIndeks];
		dugumler[ikinciIndeks] = NULL;
		dugumler[ilkIndeks] = new Dugum(0,min1->frekans+min2->frekans,min1,min2);
	}
	
}
int Huffman::MinDugumIndeks(Dugum* dugumler[])
{
	Dugum* min;
	int minIndeks=-1;
	
	for(int i=0;i<harfler;i++)
	{
		if(dugumler[i] != NULL)
		{
			min = dugumler[i];
			minIndeks = i;
			break;
		}
	}
	
	for(int i=0;i<harfler;i++)
	{
		if(dugumler[i] == NULL) continue;
		
		if(*min > *(dugumler[i]))
		{
			min = dugumler[i];
			minIndeks = i;
		}
	}
	return minIndeks;
}
void Huffman::KodOlustur(Dugum* alt_dugum,string kod)
{
	if(!alt_dugum->Yaprakmi())
	{
		KodOlustur(alt_dugum->sol,kod+'0');
		KodOlustur(alt_dugum->sag,kod+'1');
	}
	else
	{
		alt_dugum->kod = kod;
		tabloyaYaz(alt_dugum);
	}
}
void Huffman::kodlayici(Dugum* alt_dugum)
{
	for(int i=0;i<girdi.length();i++)
	{
		if(girdi[i]==' ')
		{
			AramaYap('@',alt_dugum);
		}
		else if(girdi[i]=='\n')
		{
			AramaYap('>',alt_dugum);
		}
		else
		{
			AramaYap(girdi[i],alt_dugum);
		}
	}
}
/*void Huffman::kodCozucu()
{
	string text,textTablo;
	bitOku(text);
	for(int i=0;i<text.length())
	{
		string kelimeler;
		tabloyuOku(textTablo);
		if(text[i]==textTablo)
		{
			cout<<textTablo;
		}
		kelimeler=text[i]+text[i+1];
		else if(kelimeler==textTablo)
		{
			cout<<textTablo;
		}
		
	}
}
void tabloyuOku(string textTablo)
{
	string textTablosu;
	if(dosya.is_open())
	{
		while(getline(dosya,textTablosu))
		{
			textTablo+=textTablosu;
			text+="/n";
		}
	}
	else
	{
		dosya.open("tablo.txt",ios::in);
		tabloyuOku(textTablo);
	}
}*/
void Huffman::AramaYap(char harf,Dugum* alt_dugum)
{
	if(!alt_dugum->Yaprakmi())
	{
		AramaYap(harf,alt_dugum->sol);
		AramaYap(harf,alt_dugum->sag);
	}
	else
	{
		if(alt_dugum->karakter==harf)
		{
			bitYaz(alt_dugum);
		}
	}
}
void Huffman::tabloyaYaz(Dugum* alt_dugum)
{
	if(dosya.is_open())
	{
		dosya<<alt_dugum->karakter<<":"<<alt_dugum->kod<<endl;
	}
	else
	{
		dosya.open("tablo.txt",ios::out);
		tabloyaYaz(alt_dugum);
	}
}
void Huffman::bitYaz(Dugum* alt_dugum)
{
	if(dosyaBit.is_open())
	{
		//dosyaBit<<alt_dugum->kod;
		//while (*alt_dugum) dosyaBit.put (*alt_dugum++);
		dosyaBit.write((char*)&alt_dugum->kod, sizeof(alt_dugum->kod));
	}
	else
	{
		dosyaBit.open("bit.dat",ios::binary|ios::out);
		bitYaz(alt_dugum);
	}
}
/*void Huffman::bitOku(string text)
{
	string text1;
	if(dosyaBit.is_open())
	{
		while(getline(dosyaBit,text1))
		{
			text+=text1;
			text+="/n";
		}
	}
	else
	{
		dosyaBit.open("bit.dat",ios::in|ios::binary);
	}
}*/

ostream& operator<<(ostream& ekran,Huffman& sag)
{
	ekran<<"Huffman Agacindaki Karakterler ve Kodlari:"<<endl;
	sag.inorder(sag.root);
	return ekran;
}
void Huffman::inorder(Dugum* alt_dugum)
{
	if(alt_dugum != NULL)
	{
		inorder(alt_dugum->sol);
		if(alt_dugum->Yaprakmi()) 
		{
			cout<<alt_dugum->karakter<<":"<<alt_dugum->kod<<endl;
		}
		inorder(alt_dugum->sag);
	}
}
void Huffman::SilDugum(Dugum* alt_dugum)
{
	if(alt_dugum == NULL) return;
	SilDugum(alt_dugum->sol);
	SilDugum(alt_dugum->sag);
	delete alt_dugum;
	alt_dugum = NULL;
}
Huffman::~Huffman()
{
	SilDugum(root);	
}
