OBJS := JSON.o Monster.o Adventurer.o Source.o
CFLAGS := -std=c++17 -Wall -Werror -g
CC := g++10

CPPFILES := JSON.o Monster.o Adventurer.o Source.o
CPPCFLAGS := --enable=all 2> report.txt && cat report.txt && if grep -q "(warning)" "./report.txt"; then exit 1; fi && if grep -q "(error)" "./report.txt"; then exit 1; fi

build: $(OBJS)
	$(CC) $(CFLAGS) -o output $(OBJS)

JSON.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

Monster.o: Monster.cpp Monster.h
	$(CC) $(CFLAGS) -c Monster.cpp

Adventurer.o: Adventurer.cpp Adventurer.h
	$(CC) $(CFLAGS) -c Kalandor.cpp

Source.o: Source.cpp Monster.h Adventurer.h
	$(CC) $(CFLAGS) -c Source.cpp

cppcheck:
	cppcheck $(CPPFILES) $(CPPCFLAGS)
	
unittest:
	cd tests && ./runTests
