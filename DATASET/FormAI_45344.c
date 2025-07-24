//FormAI DATASET v1.0 Category: Text processing ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size of input string

int main() {
    char input[MAX_SIZE];
    int num_vowels = 0, num_consonants = 0, num_spaces = 0, num_digits = 0;
    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; // Removing trailing newline character if any
    
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == ' ') num_spaces++;
        else if(input[i] >= 'A' && input[i] <= 'Z') {
            if(input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
                num_vowels++;
            else num_consonants++;
        }
        else if(input[i] >= 'a' && input[i] <= 'z') {
            if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
                num_vowels++;
            else num_consonants++;
        }
        else if(input[i] >= '0' && input[i] <= '9') num_digits++;
    }
    
    printf("\nAnalysis of input string:");
    printf("\nNumber of vowels: %d", num_vowels);
    printf("\nNumber of consonants: %d", num_consonants);
    printf("\nNumber of spaces: %d", num_spaces);
    printf("\nNumber of digits: %d", num_digits);
    
    return 0;
}