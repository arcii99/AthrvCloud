//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: sophisticated
#include <stdio.h>
#include <string.h>

int main() {
    char english[100];
    printf("Enter an English word or sentence to translate to Spanish: ");
    fgets(english, sizeof(english), stdin);

    // Remove \n from the end of the input string
    english[strcspn(english, "\n")] = 0;

    if (strcmp(english, "hello") == 0) {
        printf("Hola\n");
    } else if (strcmp(english, "goodbye") == 0) {
        printf("Adiós\n");
    } else if (strcmp(english, "thank you") == 0) {
        printf("Gracias\n");
    } else if (strcmp(english, "please") == 0) {
        printf("Por favor\n");
    } else {
        printf("Translation not found\n");
    }

    return 0;
}