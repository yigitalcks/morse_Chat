#include <stdio.h>
#include <string.h>

int isSpace(char *word){ // --text option'ı ile tek kelime alındığından emin olmak için
    char x;
    for (int i = 0; i < strlen(word); i++){
        x = word[i];
        if(x == ' '){
            return 0;
        }
    }
    return 1;
}