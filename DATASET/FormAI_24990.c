//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <string.h>

void alienTranslator(char alienWord[]) {
    int i;

    for (i = 0; i < strlen(alienWord); i++) {
        if (alienWord[i] == 'X') {
            printf("Hello ");
        }
        else if (alienWord[i] == 'Y') {
            printf("my ");
        }
        else if (alienWord[i] == 'Z') {
            printf("love");
        }
        else {
            printf("%c", alienWord[i]);
        }
    }
}

int main() {
    char alienWord[100];

    printf("Enter an alien word:\n");
    scanf("%s", alienWord);

    printf("The translation of %s is:\n", alienWord);
    alienTranslator(alienWord);

    return 0;
}