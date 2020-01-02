#include <stdio.h>
#define VERSION "1.0-alpha"

void fileCopy(FILE *, FILE *);

void fileCopy(FILE *src, FILE *dest){
    int c;
    while((c=fgetc(src)) != EOF){
        fputc(c, dest);
    }
}