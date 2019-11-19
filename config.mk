#B159973 - Programming Skills - 2019
#Variables of the Makefile
CC =     gcc
CFLAGS = -g  -Wl,--no-as-needed -ltcmalloc -Wl,--as-needed -Wl,--no-as-needed -lprofiler -Wl,--as-needed -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free
LDFLAGS = -lm -no-pie
OBJ_DIR = obj/
SRC_DIR = src/
BIN_DIR = bin/
INC_DIR = include/
EXE_NAME = percolate

# Object files
OBJ =   ${SRC:${SRC_DIR}%.c=${OBJ_DIR}%.o}
# Source files 	
SRC = 	${wildcard  ${SRC_DIR}*.c}
# Header files	
INC = 	${wildcard  ${INC_DIR}*.h}
# Executable file
EXE :=  ${BIN_DIR}${EXE_NAME}

