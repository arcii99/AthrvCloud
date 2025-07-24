//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Function to convert C Cat Language to English
void cCatToEnglish(char* cCat) {
    if (strcmp(cCat, "meow") == 0) {
        printf("Hello");
    } else if (strcmp(cCat, "purr") == 0) {
        printf("Goodbye");
    } else if (strcmp(cCat, "hiss") == 0) {
        printf("Stop");
    } else if (strcmp(cCat, "scratch") == 0) {
        printf("Help");
    } else {
        printf("Unknown command");
    }
}

int main() {
    char input[50];

    // get user input
    printf("Enter C Cat command: ");
    fgets(input, 50, stdin);

    // call cCatToEnglish function to translate input
    cCatToEnglish(input);

    return 0;
}