//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size of input string

// Function to translate C Cat language into English 
void translate(char *input) {
    if (strcmp(input, "meow") == 0) {
        printf("Hello!\n");
    }
    else if (strcmp(input, "purr") == 0) {
        printf("Thank you!\n");
    }
    else if (strcmp(input, "hiss") == 0) {
        printf("Goodbye!\n");
    }
    else if (strcmp(input, "scratch") == 0) {
        printf("I am excited!\n");
    }
    else if (strcmp(input, "nap") == 0) {
        printf("I am taking a nap!\n");
    }
    else if (strcmp(input, "catch") == 0) {
        printf("I caught it!\n");
    }
    else {
        printf("I do not understand.\n");
    }
}

int main() {
    char input[MAX_SIZE];
    printf("Welcome to the C Cat Language translator!\n");
    printf("Please enter a C Cat word or phrase to translate:\n");
    while (fgets(input, MAX_SIZE, stdin)) {
        if (input[strlen(input)-1] == '\n') {
            input[strlen(input)-1] = '\0';
        }
        translate(input);
    }
    return 0;
}