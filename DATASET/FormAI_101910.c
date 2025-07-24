//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: shocked
#include <stdio.h>

int main() {
    printf("Welcome to the C Cat Language Translator!\n\n");
    printf("Input your cat's meows: ");

    char meows[100];
    fgets(meows, sizeof(meows), stdin);

    int i = 0;
    while (meows[i] != '\0') {
        if (meows[i] == 'm') {
            printf("Purrr ");
        } else if (meows[i] == 'a') {
            printf("Meowwww ");
        } else if (meows[i] == 'p') {
            printf("Hiss ");
        } else if (meows[i] == 'r') {
            printf("Rrrr ");
        } else if (meows[i] == 't') {
            printf("Chirp ");
        } else {
            printf("...");
        }
        i++;
    }
    printf("\n");

    return 0;
}