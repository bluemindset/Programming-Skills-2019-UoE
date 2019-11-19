CC=	gcc

LFLAGS=	-lm

EXE=	percolate
SRC= 	$(wildcard *.c)
OBJ=	$(SRC:.c=.o)
HDS=    $(wildcard *.h)
OUTPUT= $(wildcard *.pgm) $(wildcard *.dat)
OUT_DIR = output/
all:	$(EXE)

$(EXE):	$(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LFLAGS)

%.o: %.c $(HDS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE) $(OUTPUT) 
	#rm -rf $(OUT_DIR)
