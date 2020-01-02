#include <stdio.h>

void fileCopy(FILE *, FILE *);

void fileCopy(FILE *src, FILE *dest){
    int c;
    while((c=fgetc(src)) != EOF){
        fputc(c, dest);
    }
}