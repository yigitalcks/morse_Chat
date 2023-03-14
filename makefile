CC = gcc
INC = -I./include

ifeq ($(OS), Windows_NT)
	RM = del
	EXE = .\morseChat
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
		EXE = ./morseChat
	else
		$(error unsupported OS)
	endif

	ifneq ($(shell which sox), /usr/bin/sox)
		DEP = sox
	endif
endif

terminal: $(DEP) all clean execute
help: $(DEP) morseChat clean exechelp
text: $(DEP) morseChat clean exectext
file: $(DEP) morseChat clean execfile
compile: $(DEP) morseChat clean
		
morseChat: ./src/morseChat.c ./src/failcase.o ./src/beep.o ./src/isspace.o
	@$(CC) INC $^ -o $@
all: ./src/morseChat.c ./src/failcase.c ./src/beep.c ./src/isspace.c
	@$(CC) INC $^ -o morseChat
./src/failcase.o: ./src/failcase.c
	@$(CC) -c INC $^ -o $@
./src/beep.o: ./src/beep.c
	@$(CC) -c INC $^ -o $@
./src/isspace.o: ./src/isspace.c
	@$(CC) -c INC $^ -o $@

clean:
	@cmd //C del ".\src\*.o"
execute:
	@$(EXE)
execfile:
	@$(EXE) --file $(filename)
exectext:
	@$(EXE) --text $(text)
exechelp:
	@$(EXE) --help

sox:
	sudo apt -y install sox
	