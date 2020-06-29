GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall
PROGRAMA = diary

all: $(PROGRAMA)

$(PROGRAMA): Util.o Date.o Hour.o Message.o Diary.o App.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) Util.o Date.o Hour.o Message.o Diary.o App.o main.o

Util.o: src/Util.cpp include/Util.h
	$(GCC) $(GCC_FLAGS) -c src/Util.cpp

Date.o: src/Date.cpp include/Date.h
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

Hour.o: src/Hour.cpp include/Hour.h
	$(GCC) $(GCC_FLAGS) -c src/Hour.cpp

Message.o: src/Message.cpp include/Message.h
	$(GCC) $(GCC_FLAGS) -c src/Message.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp