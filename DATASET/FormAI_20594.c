//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a sentence in C Cat Language:\n");
    fgets(input, 100, stdin);
    
    if (strstr(input, "meow") != NULL) {
        printf("Translation: Hello!\n");
    }
    else if (strstr(input, "hiss") != NULL) {
        printf("Translation: Goodbye!\n");
    }
    else if (strstr(input, "purr") != NULL) {
        printf("Translation: Thank you!\n");
    }
    else if (strstr(input, "scratch") != NULL) {
        printf("Translation: Please!\n");
    }
    else if (strstr(input, "chase") != NULL) {
        printf("Translation: Let's play!\n");
    }
    else {
        printf("Translation: I don't understand.\n");
    }
    
    printf("Thank you for using the C Cat Language Translator!\n");
    
    return 0;
}