OPT ?= -O3

CFLAGS   = -std=gnu11 $(OPT) -Wall -Wextra -Wpedantic -Wstrict-aliasing -static

EXEC=lfsr merge mm sieve spmv

all: $(EXEC)

%: %.c randArr.h spmvArr.h
	$(CC) -o $@ $< $(CFLAGS)

randArr.h:
	python rand_c_arr.py --len=8192 --range=1000000

spmvArr.h:
	python rand_spmv_arrs.py
	
clean: 
	@rm -f $(EXEC)

cleanall: clean
	@rm randArr.h spmvArr.h

