/**
 * @file  Huffman.hpp
 * @description Huffman Ağacı oluşturup karakterlerin bit karşılık tablosu ve kelimelerin bit karşılıklarını oluşturmaldır. Daha sonra deneme.txt dosyasında bulunan kelimelerin hepsinin Huffman ağacından faydalanarak bit karşılığını yeni bir dosyaya (“Bit.dat”) yazılmaldır. Burada dikkat edilmesi gereken bitlerin Bit.dat dosyasına direk bit şeklinde yazılmasıdır (Karakter türünde yazılmamalıdır). Hangi karakterin hangi bite karşılık geldiğini de ayrıca Tablo.txt dosyasına text olarak yazılacaktır. Program kapatılıp tekrar açıldığında Tablo.txt dosyasındaki tablo yardımıyla Bit.dat dosyası açılıp dosyadan bitler okunup ekrana karakter karşılıkları yazılacaktır.
 * @course  1A
 * @assignment  Odev4
 * @date  21/12/2017
 * @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
 */
#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <fstream>
#include <cstring>
#include <string>

#include "Dugum.hpp"

class Huffman{
	private:
		int harfler;  			// harflerin ASCII karşılıkları
		string girdi;			// dosyadan okunan girdi
		Dugum *root;
		fstream dosya,dosyaBit;
				
		Dugum* AgacOlustur(int frek[]);
		int MinDugumIndeks(Dugum* dugumler[]);
		void DosyaOku(string)throw(string);
		void inorder(Dugum*);
		void SilDugum(Dugum*);
	public:
		Huffman(string)throw(string);
		void bitYaz(Dugum*);
		void KodOlustur(Dugum*,string);
		void kodlayici(Dugum*);
		void AramaYap(char,Dugum*);
		void tabloyaYaz(Dugum*);
		void Kodla(int secim);
		friend ostream& operator<<(ostream&,Huffman&);
		~Huffman();
};


#endif
