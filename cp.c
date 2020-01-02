#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void usage(char *);
void help(char *);

int main(int argc, char *argv[]){

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
    FILE *from = fopen(argv[1], "r");
    FILE *to = fopen(argv[2], "w");
    fileCopy(from, to);
    return 0;
}


void usage(char *progName){
    printf("\nUsage: %s [OPTIONS] SOURCE DESTINATION\n", progName);
}

void help(char *progName){
    printf("\ncp - copy files\n");
    usage(progName);
    printf("\n--help\tdisplay this help and exit\n");
    printf("--version\t output version information and exit\n\n");
}

