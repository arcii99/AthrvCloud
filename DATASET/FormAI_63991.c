//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: enthusiastic
// Welcome to the C Cat Language Translator!

#include <stdio.h>
#include <string.h>

int main() {
    char phrase[100], translated[100];
    int i, j=0;

    printf("Hello, I am the C Cat Language Translator!\n");
    printf("Please enter a phrase you would like me to translate: ");

    fgets(phrase, sizeof(phrase), stdin);

    printf("The English phrase you entered is: %s", phrase);

    for(i=0; i < strlen(phrase); i++) {
        switch(phrase[i]) {
            case 'M':
                translated[j++] = 'M';
                translated[j++] = 'e';
                translated[j++] = 'o';
                break;
            case 'm':
                translated[j++] = 'm';
                translated[j++] = 'e';
                translated[j++] = 'o';
                break;
            case 'P':
                translated[j++] = 'P';
                translated[j++] = 'u';
                translated[j++] = 'r';
                break;
            case 'p':
                translated[j++] = 'p';
                translated[j++] = 'u';
                translated[j++] = 'r';
                break;
            case 'T':
                translated[j++] = 'T';
                translated[j++] = 'u';
                translated[j++] = 'n';
                break;
            case 't':
                translated[j++] = 't';
                translated[j++] = 'u';
                translated[j++] = 'n';
                break;
            case 'W':
                translated[j++] = 'W';
                translated[j++] = 'o';
                translated[j++] = 'o';
                break;
            case 'w':
                translated[j++] = 'w';
                translated[j++] = 'o';
                translated[j++] = 'o';
                break;
            default:
                translated[j] = phrase[i];
                j++;
        }
    }
    printf("The C Cat translation is: %s", translated);

    return 0;
}