//FormAI DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <string.h>

// Structure to represent a word and the number of times it appears in the message
typedef struct {
    char word[20];
    int count;
} Word;

int main() {
    char message[200];  // To store the message
    printf("Welcome to the Spam Detection System!\nPlease enter your message:\n");
    fgets(message, sizeof(message), stdin);  // Read the message from user input
    printf("Analyzing message for spam...\n\n");

    // Split the message into words
    char* delim = " ,.!?\n";  // Delimiters to split the message
    char* wordToken = strtok(message, delim);
    Word words[50];  // To store the unique words and their counts
    int count = 0;  // To keep track of the number of unique words

    while (wordToken != NULL) {
        // Check if the word already exists in the words array
        int i = 0;
        while (i < count && strcmp(words[i].word, wordToken) != 0) {
            i++;
        }
        if (i == count) {
            // If the word is unique, add it to the words array
            strcpy(words[count].word, wordToken);
            words[count].count = 1;
            count++;
        } else {
            // If the word already exists, increment its count
            words[i].count++;
        }
        wordToken = strtok(NULL, delim);
    }

    // Check for spam words
    int spamCount = 0;  // To keep track of the number of spam words
    for (int i = 0; i < count; i++) {
        if (strcmp(words[i].word, "buy") == 0 || strcmp(words[i].word, "sale") == 0 ||
            strcmp(words[i].word, "discount") == 0 || strcmp(words[i].word, "limited") == 0) {
            spamCount += words[i].count;
        }
    }

    if (spamCount > 0) {
        printf("Sorry, your message contains %d spam words.\n", spamCount);
    } else {
        printf("Congratulations! Your message is spam-free!\n");
    }

    return 0;  // End of program
}