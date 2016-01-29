#!/bin/bash
#
# This script takes one argumnet, and creates a makefile named from the argument
# and based off of the .cpp and .h files in the current directory.

if test $# = 0
then
	printf "Executable name required.\nusage: makemake.sh executable_name\n"
else
	echo -en "$1 : " > Makefile
	echo -en *.cpp | sed 's/.cpp/.o/g' >> Makefile
	args=""
	for i in "$@"
	do
		args+="$i "
	done
	echo -en "$extraops"	
	echo -en "  \n\tg++ -ansi -Wall -g -o " >> Makefile
	echo -en "$1" >> Makefile
	echo -en "$args" | sed "s/$1//" >> Makefile 
	echo -en *.cpp | sed 's/.cpp/.o/g' >> Makefile
	echo -en "  \n\n" >> Makefile

	for file in *.cpp
	do
		echo -en $file | sed 's/.cpp/.o/g' >> Makefile
		echo -en " :" >> Makefile
		echo -en " $file" >> Makefile
		awk '/#include "/ {printf " "$2}' $file | sed 's/"//g' | sed "s/\r//g"  >> Makefile
		echo -en " " >> Makefile
		echo -en "\n\tg++ -ansi -Wall -g -c " >> Makefile
		echo -en "$args" | sed "s/$1//" >> Makefile
		echo -en "$file\n\n" >> Makefile
	done
	echo -en "clean : \n\t" >> Makefile
	echo -en "rm -f $1 " >> Makefile
	echo -en *.cpp | sed 's/.cpp/.o /g' >> Makefile
	echo -en "  " >> Makefile
	make		

fi
