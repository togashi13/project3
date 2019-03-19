all: project3.exe

project3.o: project3.cpp ColorClass.h RowColumnClass.h ColorImageClass.h  
	g++ -Wall -c project3.cpp -o project3.o

ColorClass.o: ColorClass.cpp ColorClass.h globf_proj3.h
	g++ -Wall -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h
	g++ -Wall -c RowColumnClass.cpp -o RowColumnClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h const_proj3.h ColorClass.h RowColumnClass.h
	g++ -Wall -c ColorImageClass.cpp -o ColorImageClass.o 

project3.exe: project3.o ColorClass.o RowColumnClass.o ColorImageClass.o
	g++ -Wall project3.o ColorClass.o RowColumnClass.o ColorImageClass.o -o project3.exe

clean: 
	rm -f *.o *.exe 