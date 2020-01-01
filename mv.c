#include <stdio.h>
#include <stdlib.h>

void usage(char *);
void fileCopy(FILE *, FILE *);

int main(int argc, char *argv[]){
    if (argc < 3){
        fprintf(stderr, "%s: too few arguments\n", argv[0]);
        usage(argv[0]);
        exit(1);
    }
    if (argc > 3){
        fprintf(stderr, "%s: too many arguments\n", argv[0]);
        usage(argv[0]);
        exit(2);
    }
    FILE *from = fopen(argv[1], "r");
    FILE *to = fopen(argv[2], "w");
    fileCopy(from, to);
    remove(argv[1]);
    return 0;
}


void usage(char *progName){
    puts("mv - move files");
    printf("Usage: %s SOURCE DESTINATION\n", progName);
}

void fileCopy(FILE *src, FILE *dest){
    int c;
    while((c=fgetc(src)) != EOF){
        fputc(c, dest);
    }
}
