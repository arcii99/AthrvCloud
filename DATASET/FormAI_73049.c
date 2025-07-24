//FormAI DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000 // Maximum length of the message
#define SPAM_THRESHOLD 3 // The number of unique words in the message that marks it as spam

int main() {
    char message[MAX_MESSAGE_LENGTH]; // Initialize message array
    int uniqueWords[MAX_MESSAGE_LENGTH] = {0}; // Initialize uniqueWords array

    printf("Enter your message:\n"); // Asking user to input the message
    fgets(message, MAX_MESSAGE_LENGTH, stdin); // Reading input with fgets

    char* word = strtok(message, " "); // Initializing word pointer with first word
    while (word != NULL) {
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == '\n' || word[i] == '\r') {
                word[i] = '\0';
            }
        }
        int found = 0;
        for (int i = 0; i < MAX_MESSAGE_LENGTH; i++) { // Loop through uniqueWords array
            if (strcmp(word, &message[uniqueWords[i]]) == 0) { // If word is found in uniqueWords array
                found = 1; // Change found to true
                break; // Exit loop
            }
            if (uniqueWords[i] == 0) { // If array element is empty
                uniqueWords[i] = strlen(message); // Add word to uniqueWords array
                break; // Exit loop
            }
        }
        if (!found) { // If word is not found in uniqueWords array
            uniqueWords[strlen(message)] = strlen(message); // Add word to uniqueWords array
        }
        word = strtok(NULL, " "); // Get next word in the message
    }

    int uniqueCount = 0; // Initialize unique word count
    for (int i = 0; i < MAX_MESSAGE_LENGTH; i++) { // Loop through uniqueWords array
        if (uniqueWords[i] != 0) { // If array element is not empty
            uniqueCount++; // Increment unique word count
        } else {
            break; // Exit loop
        }
    }

    if (uniqueCount > SPAM_THRESHOLD) { // If number of unique words exceeds spam threshold
        printf("This message may be spam.\n"); // Spam warning message
    } else {
        printf("This message is not spam.\n"); // Not spam message
    }

    return 0; // End program
}