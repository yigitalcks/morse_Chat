#include "beep.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    void delay(DWORD mSecond) {
        Sleep(mSecond);
    }
    void beep_(DWORD freq, DWORD ms) {
        Beep(freq, ms);
    }
#elif
    void delay(unsigned int mSecond) {
        sleep(mSecond);
    } 
    void beep_(int freq, int ms) {
        beep(freq, ms);
    } 
#endif

void ditdah(char dat){ // dit ve dah seslendirici
    switch(dat){
        case '.':
            beep_(500, MU);
            printf(".");
            break;
        case '-':
            beep_(500, 3*MU);
            printf("-");
            break;
    }
}

void LV(char let){ // harf seslendirici
    char letter[25];
    switch(let){
        case 'a':
        case 'A':
            strcpy(letter, patterns[0]);
            break;    
        case 'b':
        case 'B':
            strcpy(letter, patterns[1]);
            break;
        case 'c':
        case 'C':
            strcpy(letter, patterns[2]);
            break;
        case 'd':
        case 'D':
            strcpy(letter, patterns[3]);
            break;
        case 'e':
        case 'E':
            strcpy(letter, patterns[4]);
            break;
        case 'f':
        case 'F':
            strcpy(letter, patterns[5]);
            break;
        case 'g':
        case 'G':
            strcpy(letter, patterns[6]);
            break;
        case 'h':
        case 'H':
            strcpy(letter, patterns[7]);
            break;
        case 'i':
        case 'I':
            strcpy(letter, patterns[8]);
            break;
        case 'j':
        case 'J':
            strcpy(letter, patterns[9]);
            break;
        case 'k':
        case 'K':
            strcpy(letter, patterns[10]);
            break;
        case 'l':
        case 'L':
            strcpy(letter, patterns[11]);
            break;
        case 'm':
        case 'M':
            strcpy(letter, patterns[12]);
            break;
        case 'n':
        case 'N':
            strcpy(letter, patterns[13]);
            break;
        case 'o':
        case 'O':
            strcpy(letter, patterns[14]);
            break;
        case 'p':
        case 'P':
            strcpy(letter, patterns[15]);
            break;
        case 'q':
        case 'Q':
            strcpy(letter, patterns[16]);
            break;
        case 'r':
        case 'R':
            strcpy(letter, patterns[17]);
            break;
        case 's':
        case 'S':
            strcpy(letter, patterns[18]);
            break;
        case 't':
        case 'T':
            strcpy(letter, patterns[19]);
            break;
        case 'u':
        case 'U':
            strcpy(letter, patterns[20]);
            break;
        case 'v':
        case 'V':
            strcpy(letter, patterns[21]);
            break;
        case 'w':
        case 'W':
            strcpy(letter, patterns[22]);
            break;
        case 'x':
        case 'X':
            strcpy(letter, patterns[23]);
            break;
        case 'y':
        case 'Y':
            strcpy(letter, patterns[24]);
            break;
        case 'z':
        case 'Z':
            strcpy(letter, patterns[25]);
            break;
        case '0':
            strcpy(letter, patterns[26]);
            break;
        case '1':
            strcpy(letter, patterns[27]);
            break;
        case '2':
            strcpy(letter, patterns[28]);
            break;
        case '3':
            strcpy(letter, patterns[29]);
            break;
        case '4':
            strcpy(letter, patterns[30]);
            break;
        case '5':
            strcpy(letter, patterns[31]);
            break;
        case '6':
            strcpy(letter, patterns[32]);
            break;
        case '7':
            strcpy(letter, patterns[33]);
            break;
        case '8':
            strcpy(letter, patterns[34]);
            break;
        case '9':
            strcpy(letter, patterns[35]);
            break;
        case '&':
            strcpy(letter, patterns[36]);
            break;
        case '\'':
            strcpy(letter, patterns[37]);
            break;
        case '@':
            strcpy(letter, patterns[38]);
            break;
        case ')':
            strcpy(letter, patterns[39]);
            break;
        case '(':
            strcpy(letter, patterns[40]);
            break;
        case ':':
            strcpy(letter, patterns[41]);
            break;
        case ',':
            strcpy(letter, patterns[42]);
            break;
        case '=':
            strcpy(letter, patterns[43]);
            break;
        case '!':
            strcpy(letter, patterns[44]);
            break;
        case '.':
            strcpy(letter, patterns[45]);
            break;
        case '-':
            strcpy(letter, patterns[46]);
            break;    
        case '+':
            strcpy(letter, patterns[47]);
            break;
        case '"':
            strcpy(letter, patterns[48]);
            break;
        case '?':
            strcpy(letter, patterns[49]);
            break;
        case '/':
            strcpy(letter, patterns[50]);
            break;
    }

    for(int i = 0; i < strlen(letter); i++){
        ditdah(letter[i]);
        if(i < strlen(letter) - 1) {
            delay(MU);
        }
    }
}

void WV(char *WORD){ // kelime seslendirici
    for(int i = 0; i < strlen(WORD); i++) {
        LV(WORD[i]);
        if (i < strlen(WORD) - 1) {
            delay(3*MU);
            printf(" ");
        }
    }
}
