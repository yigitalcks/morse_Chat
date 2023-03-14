#include <stdio.h>
#include <stdlib.h>
#include "failcase.h"

void fail(int failtype) {
    switch(failtype){
        case 0:
            printf("Usage:  make\n\tmake text text=<text>\n\tmake file filename=<file name>\n");
            break;
        case 1:
            printf("No such file\n");
            break;
        case 2:
            printf("File is too long\n");
            break;
        case 3:
            printf("Number of word is too long (MAX = 50)\n");
            break;
        case 4:
            printf("Word is too long (MAX = 30)\n");
            break;
        case 5:
            printf("No such option\n");
            break;
        case 6:
            printf("The argument must consist of only one word.\n");
            break;
    }
    exit(EXIT_FAILURE);
}