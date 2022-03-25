// C Bootcamp Demo Deliverable: Structs
// jbiggs fall 2016
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define LEN 4

// This is a definition of a struct. Things of type 'struct foo'
// will always have two longs in them: a long called bar, and a long
// called baz. Check out `main' to see how structs can be allocated.
struct foo {
    long bar;
    long baz;
};

// Structs can have different types in them, too.
struct superheroes {
    char *incredible;
    char *elastigirl;
    float frozone;
};

int main(int argc, char **argv)
{
    // declaring a struct on a stack is easy, but you can't return an
    // address to a struct when a function returns -- things get weird.
    struct foo stack_foo;
    stack_foo.bar = 3;
    stack_foo.baz = 4; // Always use "." for addressing a struct instance.

    // now a struct foo is allocated on the heap, so we have a *pointer* to
    // the struct. Accessing elements of a struct from a pointer is
    // slightly different.
    struct foo *heap_foo = malloc(sizeof(struct foo));
    heap_foo->bar = 5; // these arrows indicate that we are dereferencing
    heap_foo->baz = 6; // a struct pointer.

    // The size of struct foo and stack_foo should be the same, because
    // struct foo is the definition of the struct, and stack_foo is
    // an instance of the struct.
    printf("Size of struct foo: %lu\n", sizeof(struct foo));
    printf("Size of stack_foo: %lu\n", sizeof(stack_foo));
    // The size of heap_foo should be different, because it's a pointer
    // to a struct_foo.
    printf("Size of heap_foo: %lu\n", sizeof(heap_foo));

    // always remember to free what you malloc!
    free(heap_foo);

    struct superheroes *heroes_array = calloc(LEN, sizeof(struct superheroes));

    // Should be the same size as heap_foo, since these are both pointers.
    printf("Size of heroes_array: %lu\n", sizeof(heap_foo));
    // Careful: structs aren't always the combined size of their members!
    printf("Size of struct superheroes: %lu\n", sizeof(struct superheroes));

    // Note that heroes_array[0] is syntactic sugar for *(heroes_array + 0),
    // so we don't have to dereference the pointer again to access the field
    // of the struct. Basically, accessing an index in a struct array already
    // does the dereference for you. If we used an arrow here, the compiler
    // would complain.
    heroes_array[0].incredible = "Mr. Incredible!";
    heroes_array[0].elastigirl = "Elastigirl!";
    heroes_array[0].frozone    = 0.1137;

    // Remember: we don't need to free every field in the array, just the
    // pointer to the beginning of the array.
    free(heroes_array);
    return 0;
}
