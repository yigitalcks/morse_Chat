#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "beep.h"
#include "pattern.h"

void ditdah(char dat){ // dit ve dah seslendirici
    switch(dat){
        case '.':

            #ifdef _WIN32
                Beep(500, MU);
            #else
                system(PLAY1);
            #endif
            printf(".");
            break;
        case '-':

            #ifdef _WIN32
                Beep(500, 3*MU);
            #else
                system(PLAY3);
            #endif
            printf("-");
            break;
    }
}

void LV(char let){ // harf seslendirici
    char letter[25];
    switch(let){
        case 'a':
        case 'A':
            strcpy(letter, A);
            break;    
        case 'b':
        case 'B':
            strcpy(letter, B);
            break;
        case 'c':
        case 'C':
            strcpy(letter, C);
            break;
        case 'd':
        case 'D':
            strcpy(letter, D);
            break;
        case 'e':
        case 'E':
            strcpy(letter, E);
            break;
        case 'f':
        case 'F':
            strcpy(letter, F);
            break;
        case 'g':
        case 'G':
            strcpy(letter, G);
            break;
        case 'h':
        case 'H':
            strcpy(letter, H);
            break;
        case 'i':
        case 'I':
            strcpy(letter, I);
            break;
        
        case 'j':
        case 'J':
            strcpy(letter, J);
            break;
        case 'k':
        case 'K':
            strcpy(letter, K);
            break;
        case 'l':
        case 'L':
            strcpy(letter, L);
            break;
        case 'm':
        case 'M':
            strcpy(letter, M);
            break;
        case 'n':
        case 'N':
            strcpy(letter, N);
            break;
        case 'o':
        case 'O':
            strcpy(letter, O);
            break;
        case 'p':
        case 'P':
            strcpy(letter, P);
            break;
        case 'q':
        case 'Q':
            strcpy(letter, Q);
            break;
        case 'r':
        case 'R':
            strcpy(letter, R);
            break;
        case 's':
        case 'S':
            strcpy(letter, S);
            break;
        case 't':
        case 'T':
            strcpy(letter, T);
            break;
        case 'u':
        case 'U':
            strcpy(letter, U);
            break;
        case 'v':
        case 'V':
            strcpy(letter, V);
            break;
        case 'w':
        case 'W':
            strcpy(letter, W);
            break;
        case 'x':
        case 'X':
            strcpy(letter, X);
            break;
        case 'y':
        case 'Y':
            strcpy(letter, Y);
            break;
        case 'z':
        case 'Z':
            strcpy(letter, Z);
            break;
        case '0':
            strcpy(letter, R0);
            break;
        case '1':
            strcpy(letter, R1);
            break;
        case '2':
            strcpy(letter, R2);
            break;
        case '3':
            strcpy(letter, R3);
            break;
        case '4':
            strcpy(letter, R4);
            break;
        case '5':
            strcpy(letter, R5);
            break;
        case '6':
            strcpy(letter, R6);
            break;
        case '7':
            strcpy(letter, R7);
            break;
        case '8':
            strcpy(letter, R8);
            break;
        case '9':
            strcpy(letter, R9);
            break;
        case '&':
            strcpy(letter, AMPER);
            break;
        case '\'':
            strcpy(letter, APOS);
            break;
        case '@':
            strcpy(letter, AT);
            break;
        case ')':
            strcpy(letter, CBRACKET);
            break;
        case '(':
            strcpy(letter, OBRACKET);
            break;
        case ':':
            strcpy(letter, COLON);
            break;
        case ',':
            strcpy(letter, COMMA);
            break;
        case '=':
            strcpy(letter, EQ);
            break;
        case '!':
            strcpy(letter, EXCLAMATION);
            break;
        case '.':
            strcpy(letter, FULLS);
            break;
        case '-':
            strcpy(letter, HYPEN);
            break;    
        case '+':
            strcpy(letter, PLUS);
            break;
        case '"':
            strcpy(letter, QUOT);
            break;
        case '?':
            strcpy(letter, QUEST);
            break;
        case '/':
            strcpy(letter, SLASH);
            break;
    }

    for(int i = 0; i < strlen(letter); i++){
        ditdah(letter[i]);
        if(i < strlen(letter) - 1) {
        #ifdef _WIN32
            Sleep(MU);
        #else
            sleep(MU/1000);
        #endif    
        }
    }
}

void WV(char *WORD){ // kelime seslendirici
    for(int i = 0; i < strlen(WORD); i++) {
        LV(WORD[i]);
        if (i < strlen(WORD) - 1) {
        #ifdef _WIN32
            Sleep(3*MU);
        #else
            sleep(3*MU/1000);
        #endif    
        printf(" ");
        }
    }
}
