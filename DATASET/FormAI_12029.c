//FormAI DATASET v1.0 Category: Spam Detection System ; Style: accurate
#include <stdio.h>
#include <string.h>

// Function to check if a given word matches a spam word
int isSpamWord(char* word) {
    char* spamWords[] = {"money", "lottery", "prize", "free", "offer", "deal", "discount"};
    int numSpamWords = sizeof(spamWords) / sizeof(spamWords[0]);
    for (int i = 0; i < numSpamWords; i++) {
        if (strcmp(word, spamWords[i]) == 0) {
            return 1; // Return 1 if word matches a spam word
        }
    }
    return 0; // Return 0 if word is not a spam word
}

int main() {
    char sentence[1000];
    printf("Enter a sentence to check for spam: ");
    fgets(sentence, 1000, stdin); // Read a sentence from the user
    int numWords = 0, numSpamWords = 0;
    char* word = strtok(sentence, " \n"); // Tokenize sentence into words
    while (word != NULL) {
        numWords++;
        if (isSpamWord(word)) {
            numSpamWords++; // Count the number of spam words in the sentence
        }
        word = strtok(NULL, " \n");
    }
    double spamPercentage = (double) numSpamWords / numWords * 100;
    printf("The sentence is ");
    if (spamPercentage > 10) {
        printf("spam.\n"); // If spam percentage is more than 10%, label sentence as spam
    } else {
        printf("not spam.\n"); // If spam percentage is less than or equal to 10%, label sentence as not spam
    }
    return 0;
}