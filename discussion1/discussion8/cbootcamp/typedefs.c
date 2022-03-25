// C Bootcamp Demo Deliverable: Typedefs
// jbiggs fall 2016
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// typedef <thing you want to rename> <the name of the new thing>
typedef int number;

// of course, this gets weird when you throw in function pointers.
typedef number (*numberTransformer)(number);

number mul2(number x) {
    return x * 2;
}

int main(int argc, char** argv)
{
    // typedefs allow for code that is cleaner to read, as well
    // as increased modularity / polymorphism.
    number foo = 5;

    // numberTransformer is a type describing a function pointer
    // that takes in a 'number' type and returns another 'number' type.
    numberTransformer trans = &mul2;

    number bar = trans(foo);
    // For things like printf, treat the variable as its original type -- in
    // this case, treat it like an integer.
    printf("Bar is %d\n", bar);
    return 0;
}
