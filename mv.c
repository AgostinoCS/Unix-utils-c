#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void usage(char *);
void help(char *);

int main(int argc, char *argv[]){
    if (argc < 2){
        fprintf(stderr, "%s: too few arguments\n", argv[0]);
        usage(argv[0]);
        exit(-1);
    }    
    if(strcmp(argv[1], "--help") == 0){
        help(argv[0]);
        exit(1);
    }
    if (strcmp(argv[1], "--version") == 0){
        puts(VERSION);
        exit(2);
    } 
    if (argc < 3){
        fprintf(stderr, "%s: too few arguments\n", argv[0]);
        usage(argv[0]);
        exit(-1);
    }       
    if (argc > 3){
        fprintf(stderr, "%s: too many arguments\n", argv[0]);
        usage(argv[0]);
        exit(-2);
    }
    FILE *from, *to;
    if ((from = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "%s: cannot open %s\n", argv[0], argv[1]);
        exit(-2);
    }
    if ((to = fopen(argv[2], "w")) == NULL){
        fprintf(stderr, "%s: cannot open or create %s\n", argv[0], argv[2]);
        exit(-3);
    }
    fileCopy(from, to);
    remove(argv[1]);
    return 0;
}


void usage(char *progName){
    printf("\nUsage: %s SOURCE DESTINATION\n", progName);
}

void help(char *progName){
    printf("\nmv - move files\n");
    usage(progName);
    printf("\n--help\tdisplay this help and exit\n");
    printf("--version\t output version information and exit\n\n");    
}