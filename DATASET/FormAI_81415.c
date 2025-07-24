//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <string.h>

char translationTable[27] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q', ' '};

void alienLanguageTranslator(char* inputString) {
    int length = strlen(inputString);
    
    for (int i = 0; i < length; i++) {
        if (inputString[i] >= 'a' && inputString[i] <= 'z') {
            printf("%c", translationTable[inputString[i] - 'a']);
        } else {
            printf("%c", inputString[i]);
        }
    }
}

int main() {
    char inputString[100];
    printf("Enter a string to translate into Alien Language: ");
    scanf("%[^\n]%*c", inputString);
    printf("Alien Language Translation: ");
    alienLanguageTranslator(inputString);
    printf("\n");
    return 0;
}