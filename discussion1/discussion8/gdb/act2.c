#include <string.h>

int stc(char*, char*);

int main(int argc, char** argv)
{
    int ret = stc("cs429", argv[argc-1]);
    argv[0] = '\0';  // NOOP to force gcc to generate a callq instead of jmp
    return ret;
}