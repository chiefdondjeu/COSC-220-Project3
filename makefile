proj3Driver: studentClass.o proj3Driver.o 
	g++ -o proj3Driver studentClass.o proj3Driver.o

studentClass.o: studentClass.cpp studentClass.h
	g++ -c studentClass.cpp

proj3Driver.o: proj3Driver.cpp d_dnode.h d_dnodeBase.h
	g++ -c proj3Driver.cpp

clean:
	rm *.o