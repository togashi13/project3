all: project2.exe

project2.o: project2.cpp ColorClass.h RowColumnClass.h ColorImageClass.h  
	g++ -Wall -c project2.cpp -o project2.o

ColorClass.o: ColorClass.cpp ColorClass.h globf_pro2.h
	g++ -Wall -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h
	g++ -Wall -c RowColumnClass.cpp -o RowColumnClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h const_pro2.h ColorClass.h RowColumnClass.h
	g++ -Wall -c ColorImageClass.cpp -o ColorImageClass.o 

project2.exe: project2.o ColorClass.o RowColumnClass.o ColorImageClass.o
	g++ -Wall project2.o ColorClass.o RowColumnClass.o ColorImageClass.o -o project2.exe

clean: 
	rm -f *.o *.exe 