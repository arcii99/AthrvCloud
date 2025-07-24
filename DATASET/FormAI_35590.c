//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>

int main() {
    char alienLanguage[] = "rplx gibberish";
    char translation[] = "hello world";
    char input[100];
    int i,j,k;
    
    printf("Welcome to the Alien Language Translator!\n");
    printf("Please input the alien language message:\n");
    scanf("%[^\n]", input);
    
    for (i=0; i<strlen(input); i++) {
        if (input[i] == ' ') {
            printf(" ");
        } else {
            for (j=0; j<strlen(alienLanguage); j++) {
                if (input[i] == alienLanguage[j]) {
                    printf("%c", translation[j]);
                }
            }
        }
    }
    
    printf("\nTranslation complete. Thank you for using the Alien Language Translator!");
    
    return 0;
}