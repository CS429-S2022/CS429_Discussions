/*
 * 15-213 C Bootcamp
 *
 * This program discusses memory management and proper freeing of memory 
 * allocated on the heap. Use in conjunction with the ./mem_valgrind.sh script
 * to check for memory leaks.
 *
 * Raghav Goyal (raghavgo)
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define NUM_ARRS 4
#define BUF_SIZE 5

int main() 
{
    /* Typical malloc call:
     * TYPE *addr = malloc(NUM_ELEMS * sizeof(TYPE));
     * Take sizeof(TYPE) because we want the size of the data type that 
     * the returned address will point to.
     * Note that sizeof(TYPE) != sizeof(TYPE *) in most cases! 
     */

    // Allocate an array of pointers of size NUM_ARRS
    int *arr[NUM_ARRS];
    // Iterate through array and allocate an array of ints for each int pointer   
    for (int i = 0; i < NUM_ARRS; i++)
    {
        // Note the explicit cast to int *
        arr[i] = (int *)malloc(BUF_SIZE * sizeof(int)); 
        if (arr[i] == NULL)
        {
            printf("Malloc failed for arr[%d], aborting...", i);
            abort();
        }
        
    }
    // Suppress unused variable warning
    (void)arr;
    
    /* What is the correct way to free all allocated memory? 
     * Comment in the solution and check using valgrind!
     * Run ./mem_valgrind.sh in your terminal.
     */
    
    /*** A ***/
    /*
    for (int j = 0; j < NUM_ARRS; j++)
    {
        free(arr[j]);
    }
    */
    
    /*** B ***/
    /*
    for (int j = 0; j < NUM_ARRS; j++)
    {
        free(arr[j]);
    }
    free(arr);
    */
    
    /*** C ***/
    /*
    free(arr);
    */

    return 0;
}


