#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void usage(char *);
void help(char *);

int main(int argc, char *argv[]){
    if (argc < 2){
        fileCopy(stdin, stdout);
    }
    if (strcmp(argv[1], "--help") == 0){
        help(argv[0]);
        exit(1);
    }
    if (strcmp(argv[1], "--version") == 0){
        puts(VERSION);
        exit(2);
    }
    int i;
    FILE *file;
    for(i = 1; i < argc;i++){
        if ((file = fopen(argv[i], "r")) == NULL){
            fprintf(stderr, "%s: cannot open %s\n", argv[0], argv[i]);
            exit(-1);
        } else {
            fileCopy(file,stdout);
        }
    }
    return 0;
}


void usage(char *progName){
    printf("\nUsage: %s [OPTIONS] [FILES]\n", progName);
}

void help(char *progName){
    printf("\ncat - concatenate files and print on the standard output\n");
    usage(progName);
    printf("\n--help\tdisplay this help and exit\n");
    printf("--version\toutput version information and exit\n\n");
}