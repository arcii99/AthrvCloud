//FormAI DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int numWords = 0, numSentences = 0, numVowels = 0, i;

    printf("Enter text: ");
    fgets(text, 1000, stdin);

    // Count number of words
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            numWords++;
        }
    }

    // Count number of sentences
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            numSentences++;
        }
    }

    // Count number of vowels
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u') {
            numVowels++;
        }
    }

    printf("Number of words: %d\n", numWords + 1); // +1 to account for last word
    printf("Number of sentences: %d\n", numSentences);
    printf("Number of vowels: %d\n", numVowels);

    return 0;
}