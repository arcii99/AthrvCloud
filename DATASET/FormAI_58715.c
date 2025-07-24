//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate C Cat Language into English
void cCatTranslator(char *cCatInput) {
    char *token = strtok(cCatInput, " ");
    char *output[500];
    int outputIndex = 0;
    
    while (token != NULL) {
        if (strcmp(token, "meow") == 0) {
            output[outputIndex] = "Hello";
            outputIndex++;
        } else if (strcmp(token, "purr") == 0) {
            output[outputIndex] = "Yes";
            outputIndex++;
        } else if (strcmp(token, "hiss") == 0) {
            output[outputIndex] = "No";
            outputIndex++;
        } else if (strcmp(token, "scratch") == 0) {
            output[outputIndex] = "Goodbye";
            outputIndex++;
        } else if (strcmp(token, "pounce") == 0) {
            output[outputIndex] = "Jump";
            outputIndex++;
        } else {
            output[outputIndex] = token;
            outputIndex++;
        }
        
        token = strtok(NULL, " ");
    }
    
    printf("\nTranslated Output: ");
    for (int i=0; i<outputIndex; i++) {
        printf("%s ", output[i]);
    }
}

int main() {
    char cCatInput[1000];
    
    // Input from user
    printf("Enter C Cat Language: ");
    fgets(cCatInput, sizeof(cCatInput), stdin);
    
    // Remove newline character from input
    cCatInput[strcspn(cCatInput, "\n")] = 0;
    
    // Translate C Cat Language into English
    cCatTranslator(cCatInput);
    
    return 0;
}