//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: optimized
#include <stdio.h>
#include <string.h>

// function to translate alien language
void translate(char message[]) {
    int i, j, len;
    len = strlen(message);
    char translated[len];

    // translation rules
    for (i = 0; i < len; i++) {
        switch (message[i]) {
            case 'a':
                translated[i] = '#';
                break;
            case 'e':
                translated[i] = '@';
                break;
            case 'i':
                translated[i] = '!';
                break;
            case 'o':
                translated[i] = '*';
                break;
            case 'u':
                translated[i] = '+';
                break;
            default:
                translated[i] = message[i];
        }
    }

    // print the translated message
    printf("Translated Message: %s\n", translated);
}

int main() {
    char message[50];

    // get the message to be translated
    printf("Enter the message to be translated: ");
    scanf("%s", message);

    // call the translate function
    translate(message);

    return 0;
}