CC = gcc
LBFLAGS = -I./include -L./lib

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

terminal: $(DEP) morseChat clean execute
help: $(DEP) morseChat clean exechelp
text: $(DEP) morseChat clean exectext
file: $(DEP) morseChat clean execfile
compile: $(DEP) morseChat clean
		
morseChat: morseChat.c failcase.o beep.o isspace.o
	@$(CC) $(LBFLAGS) $^ -lbass -o $@
failcase.o: failcase.c
	@$(CC) -c $^ -o $@
beep.o: beep.c
	@$(CC) -c $^ -o $@
isspace.o: isspace.c
	@$(CC) -c $^ -o $@

clean:
	@cmd //C del *.o  $(RM) *.o
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