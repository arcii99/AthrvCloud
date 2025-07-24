//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <string.h>

// Define the maximum size for the input string
#define MAX_INPUT_SIZE 1000

// Define the threshold for spam detection
#define SPAM_THRESHOLD 0.6

// Define the spam words to be checked
char spam_words[][20] = {"money", "free", "offer", "discount", "sale"};

// Function to check if a word is a spam word
int is_spam_word(char *word) {
    int i;
    for (i = 0; i < sizeof(spam_words) / sizeof(spam_words[0]); i++) {
        if (strcmp(word, spam_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Define the input string and the words counter
    char input[MAX_INPUT_SIZE];
    int words_count = 0;
    
    // Get the input from the user
    printf("Enter your message:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    
    // Loop through the characters of the input string and count the words
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            words_count++;
        }
    }
    // Increment the words count for the last word
    words_count++;
    
    // Define the spam words counter
    int spam_words_count = 0;
    
    // Tokenize the input string to get the individual words
    char *word = strtok(input, " \n");
    while (word != NULL) {
        // Check if the word is a spam word
        if (is_spam_word(word)) {
            spam_words_count++;
        }
        word = strtok(NULL, " \n");
    }
    
    // Check if the spam percentage is above the threshold
    float spam_percentage = (float) spam_words_count / words_count;
    if (spam_percentage >= SPAM_THRESHOLD) {
        printf("This message is spam!\n");
    } else {
        printf("This message is not spam.\n");
    }
    
    return 0;
}