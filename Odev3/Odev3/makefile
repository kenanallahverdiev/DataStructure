all:derle calistir
derle:
	g++ -I ./include -o ./lib/Islem.o -c ./src/Islem.cpp
	g++ -I ./include -o ./lib/BagilListe.o -c ./src/BagilListe.cpp	
	g++ -I ./include -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include -o ./lib/Agac.o -c ./src/Agac.cpp
	g++ -I ./include -o ./bin/odev ./lib/Agac.o ./lib/Dugum.o ./lib/BagilListe.o ./lib/Islem.o ./src/main.cpp
calistir:
	./bin/odev