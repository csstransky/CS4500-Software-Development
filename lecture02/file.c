#include <stdio.h>

char* mode = "r";
FILE* ifp = fopen("in.list", mode);
if (ifp == NULL) { fprintf(stderr, "Failed"); exit(1);}
FILE* ofp = fopen("out,list", "w");
if (ofp == NULL) {

}

while(!feof(ifp)) {
    if (fscanf(ifp, "%s %d",))
}
fclose(ifp);