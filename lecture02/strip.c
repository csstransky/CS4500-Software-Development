#include <stdio.h> // defines getchar/printf
#include <string.h>

int main() {
    int c = 0, in = 0;
    char buf[2048]; 
    char* p = buf;
    while((c = getchar()) != EOF) {
        printf("%c", c);
        if (c == '<' || c=='&') 
            in = 1;
        if (in)
            *p++ = c;
        if (c == '>' || c == ';') {
            in = 0;
            *p++ = '\0';
            if (strstr(buf, "nbsp") || strstr(buf, "NBSP"))
                printf(" ");
            p = ????
        }
    }
    return 0;
}
