//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>

void displayMenu() {
    printf("Welcome to C Alien Language Translator!\n\n");
    printf("Please enter a sentence in C Alien language to be translated to English.\n");
    printf("Type 'quit' to exit.\n");
}

int main() {
    displayMenu();

    while (1) {
        char input[1000];
        printf("\nC Alien: ");
        fgets(input, 1000, stdin);

        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "quit") == 0) {
            printf("\nGoodbye!\n");
            break;
        }

        // English translations
        if (strcmp(input, "C glik") == 0) {
            printf("Hello\n");
        } else if (strcmp(input, "C salta") == 0) {
            printf("Goodbye\n");
        } else if (strcmp(input, "C rokit") == 0) {
            printf("Spaceship\n");
        } else if (strcmp(input, "C glax") == 0) {
            printf("Planet\n");
        } else if (strcmp(input, "C tronik") == 0) {
            printf("Computer\n");
        } else if (strcmp(input, "C lirpa") == 0) {
            printf("Help\n");
        } else {
            printf("Translation not found.\n");
        }
    }

    return 0;
}