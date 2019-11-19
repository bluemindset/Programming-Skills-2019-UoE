#B159973 - Programming Skills - 2019
include config.mk

.PHONY: all
all: ${EXE}
##all:		Compile and Link the object files 
$(EXE): $(OBJ)
	${CC} ${CFLAGS} $(OBJ) -o ${EXE} ${LDFLAGS}

$(OBJ): ${OBJ_DIR}%.o: ${SRC_DIR}%.c
	${CC} ${CFLAGS} -I$(INC_DIR) -c $^ -o $@

##clean:		Clean out object files and the executable.
.PHONY: clean
clean:
	rm -f $(OBJ)
	rm -f $(EXE)
	rm -f ${BIN_DIR}*.pgm
	rm -f ${BIN_DIR}*.dat

##help:		Help menu. Type 'make --command' as shown below.
.PHONY: help
help: Makefile
	@sed -n 's/^##//p' $<

##print:		Print all configuation veriables
.PHONY: print
print:	;	$(info $$CC is [${CC}])
			$(info $$CFLAGS is [${CFLAGS}])
			$(info $$LDFLAGS is [${LDFLAGS}])
			$(info $$SRC_DIR is [${SRC_DIR}])
			$(info $$OBJ_DIR is [${OBJ_DIR}])
			$(info $$BIN_DIR is [${BIN_DIR}])
			$(info $$INC_DIR is [${INC_DIR}])
			@echo "\nLocated in config.mk\n"
