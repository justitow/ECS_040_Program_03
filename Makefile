CPU.out : decoder.o main.o  reader.o registers.o instruction.o
	g++ -Wall -ansi -o CPU.out decoder.o  main.o reader.o registers.o instruction.o

decoder.o: decoder.cpp decoder.h registers.h reader.h instruction.h
	g++ -Wall -ansi -c -g decoder.cpp

main.o: main.cpp registers.h decoder.h  reader.h instruction.h
	g++ -Wall -ansi -c -g main.cpp

reader.o: reader.cpp reader.h registers.h instruction.h
	g++ -Wall -ansi -c -g reader.cpp

registers.o: registers.cpp registers.h instruction.h
	g++ -Wall -ansi -c -g registers.cpp

instruction.o: instruction.cpp instruction.h
	g++ -Wall -ansi -c -g instruction.cpp
clean:
	rm -f CPU.out decoder.o  main.o  reader.o registers.o  
