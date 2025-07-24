//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Alien Language Translator! \n");
    printf("Please enter an Alien word: ");

    // Get user input
    char alienWord[100];
    scanf("%s", alienWord);

    // Translate the word
    printf("The translation of %s is: ", alienWord);
    for(int i = 0; alienWord[i] != '\0'; i++) {
        if(alienWord[i] >= 'a' && alienWord[i] <= 'z') {
            alienWord[i] = 'c' - (alienWord[i] - 'a');
        } else if(alienWord[i] >= 'A' && alienWord[i] <= 'Z') {
            alienWord[i] = 'C' - (alienWord[i] - 'A');
        }
    }

    // Print translated word
    printf("%s \n", alienWord);

    printf("Thank you for using the Alien Language Translator! \n");

    return 0;
}