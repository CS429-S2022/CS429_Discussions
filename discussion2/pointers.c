#include "pointers.h"

#include <stdlib.h>

/****************************************
 * Note: This is meant to be the first
 * module for you to look at! Most other
 * modules will build off of information
 * used here.
 * 
 * This series of tasks is meant to
 * help you better understand how to use
 * pointers in C. This is the main C
 * concept that are (probably) new to you,
 * since pointers are abstracted away in
 * Java.
 * 
 * Simply put, a pointer is just a memory
 * address. You can think of memory as a
 * giant array of bytes, and a pointer is
 * just an index into that array. Pointers
 * are declared by adding an asterisk to
 * the data type in C, and they are
 * "de-referenced" by putting an asterisk
 * in front of the variable name. You can
 * get the address of a variable (that is,
 * get a pointer to it) by using an
 * ampersand before a variable.
 * 
 * Example:
 * int a = 10;
 * int *b;
 * b = &a;
 * *b = 2;
 * 
 * This code creates an int a with the 
 * value 10, creates a pointer to it named
 * b, and changes the value b points to
 * to 2 (which also changes the value of
 * a to 2).
 * If you were to try reading the last two
 * lines in English, it would be 
 * "b equals the address of a", and 
 * "the value at b in memory equals 2".
 ****************************************/


/****************************************
 * Why do we even need pointers? This
 * example should help illustrate why.
 * For this example, we want to swap the
 * values of a and b, which works fine
 * as long as we're in this function.
 * However, the changes we make here will
 * not be persistent after this function 
 * returns, because C is a pass by value
 * language.
 * 
 * No need to write any code here.
 * You can run all examples by running
 * with the -e flag as so: "./runner -e"
 ****************************************/
void pointers_example_1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

/****************************************
 * Building off of the example, we can
 * use pointers to remedy this issue.
 * For this task, a and b are now pointers
 * to ints, and you need to swap the
 * values pointed to, such that the change
 * is persistent. To do this, you'll need
 * to de-reference the pointers and set
 * the value that way.
 ****************************************/
void pointers_task_1(int *a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp; 
}

/****************************************
 * Sometimes, you'll need to allocate
 * memory for a variable or data structure
 * and return a pointer to it. However,
 * local variables are always stored on
 * the stack, as you'll learn later in the
 * course, and therefore it's possible
 * they end up getting overwritten once
 * the function returns.
 * 
 * In such cases, you'll want to
 * dynamically allocate memory from the
 * heap with malloc(size). This function 
 * takes the number of bytes you want to
 * allocate as an argument, and returns a
 * pointer to the space that was allocated.
 * 
 * For this task, we want to return the
 * array [4, 2, 9], and what's currently
 * written suffers from the issue I 
 * mentioned above (in fact, the compiler
 * will give you a warning about this as 
 * well, and running this code will give
 * you a segfault). Fix it by using 
 * malloc() to produce the desired result.
 * 
 * Also to note, the sizeof(data type) 
 * operator, which gets the number of bytes 
 * a data type uses, may be useful here.
 * 
 ****************************************/

int *pointers_task_2() {
    int *array = malloc(sizeof(int)*3);
    array[0] = 4;
    array[1] = 2;
    array[2] = 9;
    return array;
}

/****************************************
 * Finally, as a side note, there is no
 * garbage collector in C. Once we're 
 * done with the memory we dynamically 
 * allocate (this does not include local
 * variables), we need to manually free it 
 * with free(pointer). Forgetting to do
 * this results in a memory leak, which 
 * needless to say, is bad.
 * 
 * Don't worry about freeing things for
 * this assignment, as I need your results
 * for testing correctness and free them
 * when I'm done.
 * **************************************/