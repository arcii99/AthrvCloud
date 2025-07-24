//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
/* Energic C Text Processing Example */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000]; // declare input buffer
    printf("Enter a sentence to process: ");
    fgets(input, sizeof(input), stdin); // get input from user

    // remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // count number of words in input
    int word_count = 0;
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == ' ') {
            word_count++;
        }
    }
    word_count++; // add 1 to word count for last word

    // count number of vowels in input
    int vowel_count = 0;
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            vowel_count++;
        }
    }

    // reverse the input
    char reversed[1000];
    int j = 0;
    for(int i = strlen(input)-1; i >= 0; i--) {
        reversed[j] = input[i];
        j++;
    }
    reversed[j] = '\0';

    // print results
    printf("\n");
    printf("Number of words: %d\n", word_count);
    printf("Number of vowels: %d\n", vowel_count);
    printf("Reversed input: %s\n", reversed);

    return 0; // done processing
}