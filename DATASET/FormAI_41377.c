//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 50

// Function to convert the C Cat Language to English
void catToEnglish(char *input) {
    if(strcmp(input, "meow") == 0) {
        printf("Hello\n");
    }
    else if(strcmp(input, "purr") == 0) {
        printf("Thank you\n");
    }
    else if(strcmp(input, "hiss") == 0) {
        printf("Goodbye\n");
    }
    else if(strcmp(input, "scratch") == 0) {
        printf("Please stop\n");
    }
    else if(strcmp(input, "sleep") == 0) {
        printf("I am tired\n");
    }
    else {
        printf("I do not understand\n");
    }
}

int main() {
    char input[MAX_INPUT];
    printf("Welcome to the C Cat Language Translator\n");
    printf("Enter 'exit' to quit the program\n");
    while(1) {
        printf("Enter a C Cat Language phrase: ");
        fgets(input, MAX_INPUT, stdin);
        // remove newline character from input
        if(input[strlen(input)-1] == '\n') {
            input[strlen(input)-1] = '\0';
        }
        if(strcmp(input, "exit") == 0) {
            break;
        }
        catToEnglish(input);
    }
    printf("Goodbye!\n");
    return 0;
}