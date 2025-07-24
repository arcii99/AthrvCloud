//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[50];
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please enter the sentence in C Alien language to be translated: ");
    fgets(input, 50, stdin);

    // Remove trailing newline character from input
    input[strcspn(input, "\r\n")] = 0;

    printf("Translated sentence: ");
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == 'C' || input[i] == 'c') {
            printf("01000011");
        } else if(input[i] == 'A' || input[i] == 'a') {
            printf("01000001");
        } else if(input[i] == 'T' || input[i] == 't') {
            printf("01010100");
        } else if(input[i] == '-') {
            printf("-");
        } else {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}