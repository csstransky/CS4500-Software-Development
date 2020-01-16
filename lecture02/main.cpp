#include <stdio.h>
// Static allocation with the keyword "static"
static int sx;
static int sa[100];
static int sy;

// Stack allocation automatic by the compiler for local variables
int main() {
    int lx;
    static int sz;

    // "printf" can display the address of any identifier
    printf("%p\n", &sx); // 0x100001084
    printf("%p\n", &sa); // 0x1000010a0
    printf("%p\n", &sy); // 0x100001230
    printf("%p\n", &lx); // 0x7fff5fbff58c
    printf("%p\n", &sz); // 0x100001080
    printf("%p\n", &main);//0x1000000dfc
    printf("%d\n", sizeof(char));  // 1

    // int x = -1;
    // size_t y = 2;
    // size_t dude = x + y;
    // printf("%d\n", dude);  // 1


    for(int* p=(int*)0x100001084;p<=(int*)0x100001230;p++) {
        *p = 0x42;
    }
    printf("%p\n", &sx);  // 0x42
    printf("%p\n", &sa[0]);  // 0x42
    printf("%p\n", &sa[1]);  // 0x42

}

