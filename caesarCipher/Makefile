all: caesarCipher

caesarCipher: caesarCipher.o 
	g++ -Wall caesarCipher.o -o caesarCipher

caesarCipher.o: caesarCipher.cpp
	g++ -c -Wall caesarCipher.cpp

clean: 
	rm -rf *.o caesarCipher