//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
    char alienLanguage[] = {'*', '%', '!', '-', '+', '=', '?', '#'};
    char humanLanguage[] = {'a', 'e', 'i', 'o', 'u', 'y', ' ', '.'};
    char inputString[100];
    int i, j, k;

    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please enter an alien sentence to be translated:\n");
    fgets(inputString, 100, stdin);

    printf("\nTranslated sentence:\n");
    for(i=0; i<strlen(inputString); i++) {
        for(j=0; j<8; j++) {
            if(inputString[i] == alienLanguage[j]) {
                printf("%c", humanLanguage[j]);
            }
        }
    }

    printf("\n\nThank you for using the C Alien Language Translator!");
    return 0;
}