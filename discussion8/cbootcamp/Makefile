CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=gnu99

all: passing_args pointer_arith mem_mgmt structs typedefs casting

structs:
	$(CC) -o structs structs.c 

typedefs:
	$(CC) -o typedefs typedefs.c 

casting: casting.c
	$(CC) $(CFLAGS) -o casting casting.c

passing_args: passing_args.c
	$(CC) $(CFLAGS) -o passing_args passing_args.c 

pointer_arith: pointer_arith.c
	$(CC) $(CFLAGS) -o pointer_arith pointer_arith.c 
	
mem_mgmt: mem_mgmt.c
	$(CC) $(CFLAGS) -o mem_mgmt mem_mgmt.c 

.PHONY: clean
clean:
	rm -f passing_args pointer_arith mem_mgmt structs typedefs casting
