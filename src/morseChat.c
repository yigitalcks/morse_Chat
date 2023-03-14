#include "..\include\beep.h"

int main(int argc, char *argv[]) {
    char x[31];
    char *words[51];
    int i = 0;
    int counter = 0;

    switch(argc) {
        case 1:
            printf("Text to be converted(Each word must not be longer than 30 characters): ");
            scanf("%s", x);

            words[0] = malloc(sizeof(char) * (strlen(x) + 1));
            strcpy(words[0], x);
            counter++;

            while(strcmp(words[i], ".") != 0) {
                i++;

                printf("Text to be converted: ");
                scanf("%s", x);

                words[i] = malloc(sizeof(char)*(strlen(x) + 1));
                strcpy(words[i], x);
                counter++;

                if(i == 49) {
                    break;
                }
            }
            for(int j = 0; j < counter - 1; j++) {
                WV(words[j]);
                printf(" %s", words[j]);
                if(j < (counter - 2)){
                    delay(7*MU);
                    printf("\n");
                }
            }
            #ifndef _WIN32
                printf("\n");
            #endif
            break;
        case 2:
            if (!(strcmp(argv[1], "--help"))) {
                #ifndef _WIN32
                    system("cat help.txt");
                    printf("\n");
                #else
                    system("type help.txt");
                #endif
            }
            else {
                fail(0);
            }
            break;
        case 3:
            if(argv[1][0] == '-') {
                char *opt = &argv[1][1];
                if(strcmp(opt, "-text") == 0 || strcmp(opt, "t") == 0) {
                    words[i] = malloc(sizeof(char)*(strlen(argv[2]) + 1));
                    strcpy(words[i], argv[2]);

                    if (isSpace(words[0])) {
                        WV(words[0]);
                        printf(" %s", words[0]);
                        #ifndef _WIN32
                            printf("\n");
                        #endif
                    } else {
                        fail(6);
                    }
                }
                else if(strcmp(opt, "-file") == 0 || strcmp(opt, "f") == 0) {
                    FILE *fp;
                    fp = fopen(argv[2], "r+");
                    
                    if(fp != NULL) {

                        counter = 0;
                        while (!(feof(fp))) {
                            fscanf(fp, "%s", x);

                            words[i] = malloc(sizeof(char)*(strlen(x) + 1));
                            strcpy(words[i], x);

                            i++;
                            counter++;
                        }
                        i--; // free() yaparken case 1 ile aynı döngüyü kullamak için
                        fclose(fp);

                        for(int j = 0; j < counter; j++) {
                            WV(words[j]);
                            printf(" %s", words[j]);
                            if(j < (counter - 1)){
                                delay(7*MU);
                                printf("\n");
                            }
                        }
                        #ifndef _WIN32
                            printf("\n");
                        #endif
                    } else {
                        fail(1);
                    }
                } else {
                    fail(5);
                }
            } else {
                fail(0);
            }
            break;
        default:
            fail(0);
            break;
    }
    if(argc == 1 || argc == 3){
        for(int j = 0; j <= i; j++) {
            free(words[j]);
        }
    }
}
