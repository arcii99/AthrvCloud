//FormAI DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, 100, stdin); // Get user input

    // Remove any leading and trailing whitespaces
    int len = strlen(input);
    int start = 0, end = len - 1;
    while(input[start] == ' ' || input[start] == '\n') {
        start++;
    }
    while(input[end] == ' ' || input[end] == '\n') {
        end--;
    }
    input[end+1] = '\0';
    memmove(input, input+start, end-start+2); // Shift string to beginning

    // Replace all whitespaces with underscore
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == ' ') {
            input[i] = '_';
        }
    }

    // Count number of vowels and consonants
    int vowels = 0, consonants = 0;
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            vowels++;
        } else if(input[i] >= 'a' && input[i] <= 'z') { // check if it's a letter
            consonants++;
        }
    }

    printf("Processed sentence: %s\n", input);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}