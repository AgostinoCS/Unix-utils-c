#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    if(argc == 1){
        while(true){
            puts("y");
        } 
    } else while(true){
        int i = 1;
        while(i < argc){
            printf("%s", argv[i]);
            if(i < argc){
                printf(" ");
            }
            ++i;
        }
        printf("\n");
    }
    return 0;
}