CC := gcc

FLAGS := -std=c99
FLAGS += -Wall

INC := -I ../
INC += -I ../ANSI/

LIB := -lm

FILES := ../Test/Test.c
FILES += ../Steinhart_Hart_Coefficients.c


.PHONY: default
default: buildDirectory
	$(CC) $(FLAGS) main-Steinhart_Hart_Test.c $(FILES) -o ./build/Steinhart_Hart_Test $(INC) $(LIB)

.PHONY: run
run: default
	./build/Steinhart_Hart_Test

buildDirectory:
	if [ ! -d "./build" ]; then mkdir build; fi
