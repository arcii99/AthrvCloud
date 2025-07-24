//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100]; // reserve space for 100 character input
    printf("Enter sentence in Alien Language: ");
    scanf("%s", input);

    char vowels[] = {'a', 'e', 'i', 'o', 'u'}; // define array of vowels
    int numVowels = sizeof(vowels) / sizeof(vowels[0]); // calculate number of vowels

    int len = strlen(input); // calculate length of input
    char output[100]; // reserve space for 100 character output
    int outputIndex = 0; // initialize output index to 0
    
    for (int i = 0; i < len; i++) {
        char letter = input[i];
        if (letter == ' ') { // if there is a space in input, add space to output
            output[outputIndex] = ' ';
            outputIndex++;
            continue;
        }

        int foundVowel = 0; // flag to keep track of whether a vowel has been found
        for (int j = 0; j < numVowels; j++) {
            if (letter == vowels[j]) { // if current letter is a vowel, add to output and set flag to 1
                output[outputIndex] = letter;
                outputIndex++;
                foundVowel = 1;
                break;
            }
        }

        if (!foundVowel) { // if no vowel was found, add the letter twice to output
            output[outputIndex] = letter;
            outputIndex++;
            output[outputIndex] = letter;
            outputIndex++;
        }
    }

    // output final translated sentence
    printf("Translation: %s", output);
    
    return 0;
}