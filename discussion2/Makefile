# These are variables defined for the makefile.
# Similar to #define's in C, the makefile will
# replace anything inside $(VAR) in a command
# with whatever VAR is equal to. Here, I've
# made variables for the compiler, compiler flags,
# and dependencies to compile.
CC = gcc
CFLAGS = -Wall -O2 -ggdb -o runner
DEPS = main.c pointers.c strings.c

# These are targets defined for the makefile.
# Simply typing "make" in the terminal will
# just run the first target, so in this case
# it's equivalent to "make all". These targets
# are just sequences of terminal commands that
# allow for more streamlined compiling - it's
# much more convenient to type "make all" than
# it is to type "gcc -Wall -Werror -O2 -ggdb 
# -o runner -DPOINTERS -DSTRINGS -DFUNCTIONS 
# -DDATA_STRUCTURES main.c pointers.c strings.c 
# functions.c data_structures.c"
all:
	$(CC) $(CFLAGS) -DPOINTERS -DSTRINGS  $(DEPS)
	./runner

pointers:
	$(CC) $(CFLAGS) -DPOINTERS main.c pointers.c
	./runner

strings:
	$(CC) $(CFLAGS) -DSTRINGS main.c strings.c
	./runner

# Finally, this target is just used to remove 
# any executables leftover for when you're done
# - it's usually good practice to not include
# these when you make a commit or submission.
clean:
	rm -rf *.o runner