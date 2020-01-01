#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void usage(char *);

int main(int argc, char *argv[]) {
   if(argc == 1){
   printf("%s", "\n");
   exit(0);
   }
   bool n = false;
   int i = 1;

   if(strchr(argv[1], '-') != NULL)
      if(argv[1][1] == 'n'){
         n = true;
         i = 2;
      } if(argv[1][1] == 'h') {
           usage(argv[0]);
           exit(0);
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
   printf("echo - display a line of text\n");
   printf("%s [option] [string]\n\n", progName);
   printf("-n\tdo not output the trailing newline\n");
   printf("-h\tdisplay this help and exit\n\n");
}