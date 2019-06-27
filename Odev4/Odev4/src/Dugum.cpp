/**
 * @file  Dugum.cpp
 * @description Huffman Ağacı oluşturup karakterlerin bit karşılık tablosu ve kelimelerin bit karşılıklarını oluşturmaldır. Daha sonra deneme.txt dosyasında bulunan kelimelerin hepsinin Huffman ağacından faydalanarak bit karşılığını yeni bir dosyaya (“Bit.dat”) yazılmaldır. Burada dikkat edilmesi gereken bitlerin Bit.dat dosyasına direk bit şeklinde yazılmasıdır (Karakter türünde yazılmamalıdır). Hangi karakterin hangi bite karşılık geldiğini de ayrıca Tablo.txt dosyasına text olarak yazılacaktır. Program kapatılıp tekrar açıldığında Tablo.txt dosyasındaki tablo yardımıyla Bit.dat dosyası açılıp dosyadan bitler okunup ekrana karakter karşılıkları yazılacaktır.
 * @course  1A
 * @assignment  Odev4
 * @date  21/12/2017
 * @author  Kenan Allakhverdiev kenan.allakhverdiev@ogr.sakarya.edu.tr
 */
#include "Dugum.hpp"

		Dugum::Dugum(char kr,int frek, Dugum* sl,Dugum *sg){
			karakter=kr;
			frekans=frek;
			sol=sl;
			sag=sg;
			kod="";
		}
		bool Dugum::Yaprakmi() const{
			if(sol == NULL && sag == NULL) return true;
			return false;
		}
		bool Dugum::operator==(Dugum& sag){
			if(this->karakter == sag.karakter) return true;
			else return false;
		}
		bool Dugum::operator!=(Dugum& sag){
			if(this->karakter != sag.karakter) return true;
			else return false;
		}
		bool Dugum::operator>(Dugum& sag){
			if(this->frekans > sag.frekans) return true;
			else return false;
		}
