/*
 * 15-213 C Bootcamp
 *
 * This program demonstrates the difference between the call-by-value and 
 * call-by-reference principles.
 *
 * Raghav Goyal (raghavgo)
 *
 */
 
#include <stdlib.h>
#include <stdio.h>

/* Call-by-value
 * C is a call-by-value language. Changes made to arguments passed into a 
 * function are NOT seen by the calling function. 
 */
void test_val(int a, int b)
{
    printf("Test_val: before add, a = %d, b = %d\n", a, b);
    a = a + b; // Modify local variable
    printf("Test_val: after add, a = %d, b = %d\n", a, b);
}

/* Call-by-reference 
 * In this case, arguments are pointers to the memory locations in which 
 * variables used by the calling function are stored. Changes made by 
 * dereferencing these pointers directly modify memory and thus can be seen 
 * by the calling function.
 */
void test_ref(int *ptr_a, int *ptr_b)
{
    printf("Test_ref: before add, *ptr_a = %d, *ptr_b = %d\n", *ptr_a, *ptr_b);
    *ptr_a = *ptr_a + *ptr_b; // Directly modify memory
    printf("Test_ref: after add, *ptr_a = %d, *ptr_b = %d\n", *ptr_a, *ptr_b);
}

int main() 
{
    int a = 213;
    int b = 513;
    printf("Main: int a = %d, int b = %d\n\n", a, b);
    
    printf("Calling test_val(a, b)...\n");
    test_val(a, b);
    printf("Main: after test_val, a = %d, b = %d ... Did test_val do anything?\n\n", a, b);

    printf("Calling test_ref(&a, &b)...\n");
    test_ref(&a, &b);
    printf("Main: after test_ref, a = %d, b = %d ... Did test_ref do anything?\n", a, b);

    /* Lesson to learn: 
     * If you want to change the value of a variable, struct, etc., inside
     * another function, pass in POINTERS to those variables 
     * (call-by-reference) instead of the variables themselves
     */

    return 0;
}


