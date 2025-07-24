//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <string.h>

// Function to translate input string into Alien Language
void translate(char input[]) {
    int length = strlen(input);
    char output[length];
    for(int i = 0; i < length; i++) {
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            output[i] = input[i] + 3; // Add 3 to vowels
        }
        else if(input[i] == ' ') {
            output[i] = input[i];
        }
        else {
            output[i] = input[i] + 1; // Add 1 to consonants
        }
    }
    printf("Input: %s\n", input);
    printf("Output: %s\n", output);
}

int main() {
    char input[50];
    printf("Enter a string to translate into Alien Language: ");
    fgets(input, 50, stdin);
    translate(input);
    return 0;
}