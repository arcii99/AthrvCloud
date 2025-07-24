//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    printf("Let's process some text with energy!\n");

    // prompt user to enter a sentence
    printf("Enter a sentence: ");
    char sentence[100];
    fgets(sentence, 100, stdin);

    // convert sentence to uppercase
    for(int i = 0; i < strlen(sentence); i++) {
        sentence[i] = toupper(sentence[i]);
    }
    printf("Your sentence in uppercase: %s\n", sentence);

    // count number of vowels in sentence
    int num_vowels = 0;
    for(int i = 0; i < strlen(sentence); i++) {
        char c = sentence[i];
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            num_vowels++;
        }
    }
    printf("Number of vowels in your sentence: %d\n", num_vowels);

    // reverse the sentence
    char reversed[100];
    int j = 0;
    for(int i = strlen(sentence)-1; i >= 0; i--) {
        reversed[j] = sentence[i];
        j++;
    }
    reversed[j] = '\0';
    printf("Your sentence reversed: %s\n", reversed);

    // replace vowels with asterisks
    char asterisked[100];
    j = 0;
    for(int i = 0; i < strlen(sentence); i++) {
        char c = sentence[i];
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            asterisked[j] = '*';
        } else {
            asterisked[j] = c;
        }
        j++;
    }
    asterisked[j] = '\0';
    printf("Your sentence with vowels replaced with asterisks: %s\n", asterisked);

    printf("Thanks for processing text with me! Goodbye!\n");

    return 0;
}