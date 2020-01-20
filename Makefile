CFLAGS   = -std=gnu11 -O3 -Wall -Wextra -Wpedantic -Wstrict-aliasing

EXEC=lfsr merge mm sieve spmv

all: $(EXEC)

%: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean: 
	@rm -f $(EXEC)
