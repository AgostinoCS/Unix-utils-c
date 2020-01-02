#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

void usage(char *);
void help(char *);

int main(int argc, char *argv[]) {
   if(argc == 1){
   printf("%s", "\n");
   exit(0);
   }
    if (strcmp(argv[1], "--help") == 0){
        help(argv[0]);
        exit(1);
    }
    if (strcmp(argv[1], "--version") == 0){
        puts(VERSION);
        exit(2);
    }
   bool n = false;
   int i = 1;

   if(strchr(argv[1], '-') != NULL)
      if(argv[1][1] == 'n'){
         n = true;
         i = 2;
      } 

   for(;i < argc; i++) {
      printf("%s",argv[i]);
      if (i < argc-1)
         printf ("%s", " ");
   }
   if(n == 0)
      printf("%s", "\n");
   return 0;
}

void usage(char *progName){
   printf("\n%s [option] [string]\n", progName);
}

void help(char *progName){
   printf("\necho - display a line of text\n");
   usage(progName);
   printf("\n-n\tdo not output the trailing newline\n");
   printf("\n--help\tdisplay this help and exit\n");
   printf("--version\t output version information and exit\n\n");
}