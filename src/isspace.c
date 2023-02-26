#include <stdio.h>
#include <string.h>
#include "../include/isspace.h"

int isSpace(char *word){ // to ensure that a single word is entered from CL with --text option
    char x;
    for (int i = 0; i < strlen(word); i++){
        x = word[i];
        if(x == ' '){
            return 0;
        }
    }
    return 1;
}