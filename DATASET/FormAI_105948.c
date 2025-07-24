//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

/**
 * This program allows the user to enter a sentence, and it will count and display the number of vowels in the sentence.
 * It also replaces all vowels with the letter 'z'.
 * The program performs these operations peacefully, without modifying the user's original sentence.
 */

int main() {
    char input[100];
    char output[100];
    int vowels = 0;
    
    printf("Please enter a sentence: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; //removes newline character from input
    
    //copying input to output string
    strcpy(output, input);
    
    //counting vowels and replacing them with 'z'
    for(int i = 0; i < strlen(input); i++){
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'
            || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
            output[i] = 'z';
            vowels++;
        }
    }
    
    printf("\nOriginal sentence: %s\n", input);
    printf("Modified sentence: %s\n", output);
    printf("Number of vowels: %d", vowels);
    return 0;
}