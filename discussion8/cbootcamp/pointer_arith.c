/*
 * 15-213 C Bootcamp
 *
 * This program gives examples of casting and pointer arithmetic. 
 *
 * Raghav Goyal (raghavgo)
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 100

int main() 
{
    // Allocate a buffer
    char *A = malloc(BUFFER_SIZE);
    printf("A = %p\n", A);
 
    /* The following arithmetic examples are to show you how the ~type~ of 
     * the pointer affects arithmetic done on the pointer. 
     * When adding x to a pointer A (i.e. A + x), the result is really
     * (A + x * sizeof(TYPE_OF_PTR_A)).
     *
     * Remember to explicitly cast a pointer when doing arithmetic! 
     * Remember to put the sizes of different types on your midterm cheat sheet! 
     */
 
    /* char is 1 byte wide
     * B = A + (5 * 1) 
     *   = A + 0x5
     */
    char *B = (A + 5); 
    printf("B = (A + 5) = A + 0x5 = %p\n", B);

    /* short is 2 bytes wide
     * C = A + (2 * 2) 
     *   = A + 0x4
     */
    char *C = (char *)(((short *) A) + 2);
    printf("C = (((short *) A) + 2) = A + 0x4 = %p\n", C);

    /* int is 4 bytes wide, Char is 1 byte wide
     * D = (A + (3 * 4) + 7 * 1)
     *   = A + 19 
     *   = A + 0x13
     */
    char *D = ((char *)(((int *) A) + 3) + 7);
    printf("D = ((char *)(((int *) A) + 3) + 7) = A + 0x13 = %p\n", D);    

    /* int* and char*  (or any other pointer) is 8 bytes wide 
     * E = (((A + (2 * 8)) + 3 * 8) + 4 * 1)
     *   = A + 16 + 24 + 4
     *   = A + 44
     *   = A + 0x2C
     */
    char *E = ((char *)((int **)(((char **) A) + 2) + 3) + 4);
    printf("E = ((char *)((int **)(((char **) A) + 2) + 3) + 4) = A + 0x2C = %p\n", E);    
    
    // Clean up memory
    free(A);
    
    return 0;
}


