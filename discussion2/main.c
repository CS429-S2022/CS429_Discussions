#ifdef POINTERS
#include "pointers.h"
#endif
#ifdef STRINGS
#include "strings.h"
#endif
#ifdef FUNCTIONS
#include "functions.h"
#endif
#ifdef DATA_STRUCTURES
#include "data_structures.h"
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SIZE 80
#define NUM_POINTER_TASKS 2
#define NUM_STRING_TASKS 3
#define NUM_FUNCTION_TASKS 2
#define NUM_DATA_STRUCTURE_TASKS 3

/********************************
 * Any modifications to this
 * file will not be reflected in
 * your final submission.
 * ******************************/

#ifdef POINTERS
static int pointer_tests() {
    /* Verify pointer tasks */
    int tests_passed = 0;

    /* Task 1 */
    int a = 10, b = 2;
    pointers_task_1(&a, &b);
    if (a == 2 && b == 10) {
        printf("Passed pointers task 1\n");
        tests_passed += 1;
    }
    else {
        printf("Failed pointers task 1\n\tYour output: %d, %d\n\tCorrect output: 2, 10\n", a, b);
    }

    /* Task 2 */
    int *answer = pointers_task_2();
    int child_status;
    pid_t child = fork();

    if(child == -1) {
        exit(1);
    }
    if(child == 0) {
        if (answer[0] == 4 && answer[1] == 2 && answer[2] == 9){
            free(answer);
            exit(0);
        }
        exit(1);
    }
    else {
        waitpid(child, &child_status, 0);
        if(!child_status) {
            printf("Passed pointers task 2\n");
            free(answer);
            tests_passed += 1;
        }
        else if(child_status == 1){
            printf("Failed pointers task 2\n\tYour output: [%d, %d, %d]\n\tCorrect output: [4, 2, 9]\n", answer[0], answer[1], answer[2]);
            free(answer);
        }
        else {
            printf("Failed pointers task 2\n\tYour output: Segmentation Fault\n\tCorrect output: [4, 2, 9]\n");
        }
    }

    

    return tests_passed;
}
#endif

#ifdef STRINGS
/* Initialize the string buffer. */
static void init_buffer(char *buf, size_t len) {
    for(int i = 0; i < len; i++) {
        buf[i] = 'a' + (i%26);
    }
    buf[len-1] = 0;
}

static int string_tests() {
    /* Verify string tasks */
    int tests_passed = 0;
    char buf[BUF_SIZE];
    init_buffer(buf, BUF_SIZE);

    /* Task 1 */
    strings_task_1(buf);
    char *answer = "CS429";

    if(!strcmp(buf, answer)) {
        printf("Passed strings task 1\n");
        tests_passed += 1;
    }
    else {
        printf("Failed strings task 1\n\tYour output: %s\n\tCorrect output: %s\n", buf, answer);
    }

    /* Task 2 */
    init_buffer(buf, BUF_SIZE);
    buf[12] = 0;

    strings_task_2(buf);
    answer = "ABCDEFGHIJKL";

    if(!strcmp(buf, answer)) {
        printf("Passed strings task 2\n");
        tests_passed += 1;
    }
    else {
        printf("Failed strings task 2\n\tYour output: %s\n\tCorrect output: %s\n", buf, answer);
    }

    /* Task 3 */
    init_buffer(buf, BUF_SIZE);
    buf[16] = 0;

    answer = strings_task_3(buf);

    if(answer && !strcmp(buf, answer)) {
        printf("Passed strings task 3\n");
        tests_passed += 1;
        free(answer);
    }
    else {
        printf("Failed strings task 3\n\tYour output: %s\n\tCorrect output: %s\n", answer, buf);
    }
    return tests_passed;
}
#endif

// These two are unused, they will likely be done next week.
#ifdef FUNCTIONS
static int function_tests() {
    return 0;
}
#endif

#ifdef DATA_STRUCTURES
static int data_structure_tests() {
    return 0;
}
#endif

/* Run all tests. */
int main(int argc, char **argv) {

    int tests_passed = 0;
    int total_tests = 0;
    
    #ifdef POINTERS
    int run_examples = 0;
    int flag;

    while ((flag = getopt(argc, argv, "e")) != -1) {
        switch(flag) {
            case 'e':
                run_examples = 1;
                break;
        }
    }

    if(run_examples) {
        int a = 10, b = 2;
        printf("Pointer example:\n\tInitial numbers:%d, %d\n", a, b);
        pointers_example_1(a, b);
        printf("\tAfter (broken) swap: %d, %d\n", a, b);
    }

    tests_passed += pointer_tests();
    total_tests += NUM_POINTER_TASKS;
    printf("-------------------------------\n");
    #endif

    #ifdef STRINGS
    tests_passed += string_tests();
    total_tests += NUM_STRING_TASKS;
    printf("-------------------------------\n");
    #endif

    #ifdef FUNCTIONS
    tests_passed += function_tests();
    total_tests += NUM_FUNCTION_TASKS;
    printf("-------------------------------\n");
    #endif

    #ifdef DATA_STRUCTURES
    tests_passed += data_structure_tests();
    total_tests += NUM_DATA_STRUCTURE_TASKS;
    printf("-------------------------------\n");
    #endif
    
    printf("Total tasks passed: %d out of %d\n", tests_passed, total_tests);
    
    return 0;
}