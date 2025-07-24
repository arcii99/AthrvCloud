//FormAI DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
    char myString[100]; // initializing the character array
    printf("Enter a sentence: ");
    fgets(myString, 100, stdin); // inputting the string
    printf("Original string: %s", myString);

    int vowelsCount = 0; // initializing a variable to count vowels
    int consonantsCount = 0; // initializing a variable to count consonants

    // counting the number of vowels and consonants
    for (int i = 0; i < strlen(myString); i++) {
        if (myString[i] == 'a' || myString[i] == 'e' || myString[i] == 'i' ||
            myString[i] == 'o' || myString[i] == 'u') {
            vowelsCount++;
        } else if ((myString[i] >= 'a' && myString[i] <= 'z') || 
                   (myString[i] >= 'A' && myString[i] <= 'Z')) {
            consonantsCount++;
        }
    }

    printf("Number of vowels: %d\nNumber of consonants: %d\n",
           vowelsCount, consonantsCount);

    // making all letters uppercase
    for (int i = 0; i < strlen(myString); i++) {
        if (myString[i] >= 'a' && myString[i] <= 'z') {
            myString[i] -= 32;
        }
    }

    printf("Uppercase string: %s\n", myString);

    // counting the number of spaces
    int spacesCount = 0;
    for (int i = 0; i < strlen(myString); i++) {
        if (myString[i] == ' ') {
            spacesCount++;
        }
    }

    printf("Number of spaces: %d\n", spacesCount);

    // replacing all the vowels with an '*'
    for (int i = 0; i < strlen(myString); i++) {
        if (myString[i] == 'a' || myString[i] == 'e' || myString[i] == 'i' ||
            myString[i] == 'o' || myString[i] == 'u' ||
            myString[i] == 'A' || myString[i] == 'E' || myString[i] == 'I' ||
            myString[i] == 'O' || myString[i] == 'U') {
            myString[i] = '*';
        }
    }

    printf("New string with vowels replaced: %s\n", myString);

    return 0;
}