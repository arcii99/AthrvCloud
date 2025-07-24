//FormAI DATASET v1.0 Category: Spam Detection System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 100
#define MAX_MSG_LENGTH 1000

// Define a struct for each potential spam message
typedef struct SpamMessage {
    char message[MAX_MSG_LENGTH];
    double spamProbability;
} SpamMessage;

// Define a struct for a spam word with frequency count
typedef struct SpamWord {
    char word[MAX_MSG_LENGTH];
    int frequency;
} SpamWord;

// Function to tokenize a message into individual words
int tokenize(char *message, char **words) {
    int count = 0;
    char *ptr = strtok(message, " ");
    while (ptr != NULL && count < MAX_MSG_LENGTH) {
        words[count] = ptr;
        count++;
        ptr = strtok(NULL, " ");
    }
    return count;
}

// Function to increment the frequency of a given spam word in an array of SpamWords
void incrementSpamWordFrequency(char *word, SpamWord *spamWords, int *numSpamWords) {
    for (int i = 0; i < *numSpamWords; i++) {
        if (strcmp(word, spamWords[i].word) == 0) {
            spamWords[i].frequency++;
            return;
        }
    }
    // Add a new spam word if it doesn't already exist
    strcpy(spamWords[*numSpamWords].word, word);
    spamWords[*numSpamWords].frequency = 1;
    (*numSpamWords)++;
}

// Function to train the spam detection system on a set of messages
void train(SpamMessage *messages, int numMessages, SpamWord **spamWords, int *numSpamWords) {
    // Create an array of SpamWords and get a count of the total number of words in our messages
    int wordCount = 0;
    for (int i = 0; i < numMessages; i++) {
        wordCount += tokenize(messages[i].message, NULL);
    }
    *spamWords = malloc(sizeof(SpamWord) * MAX_SPAM_WORDS);
    *numSpamWords = 0;

    // Tokenize each message, and check each word against our list of SpamWords
    char *words[MAX_MSG_LENGTH];
    for (int i = 0; i < numMessages; i++) {
        tokenize(messages[i].message, words);
        for (int j = 0; j < sizeof(words) / sizeof(words[0]) && words[j] != NULL; j++) {
            incrementSpamWordFrequency(words[j], *spamWords, numSpamWords);
        }
    }
}

// Function to calculate the probability that a given message is spam
double getSpamProbability(char *message, SpamWord *spamWords, int numSpamWords) {
    // Tokenize the message and calculate the spam probability based on the frequency of each spam word
    char *words[MAX_MSG_LENGTH];
    int wordCount = tokenize(message, words);
    double probability = 0.0;
    for (int i = 0; i < sizeof(words) / sizeof(words[0]) && words[i] != NULL; i++) {
        for (int j = 0; j < numSpamWords; j++) {
            if (strcmp(words[i], spamWords[j].word) == 0) {
                probability += (double) spamWords[j].frequency / (double) wordCount;
                break;
            }
        }
    }
    return probability;
}

// Main function for testing the spam detection system
int main(void) {
    // Train the spam detection system on a set of messages
    SpamMessage messages[] = {
        {"Buy our new product and get 50% off today only!"},
        {"Congratulations! You've won a free vacation!"},
        {"Meet local singles in your area tonight!"},
        {"Just a friendly reminder to pay your rent on time."}
    };
    SpamWord *spamWords = NULL;
    int numSpamWords = 0;
    train(messages, sizeof(messages) / sizeof(messages[0]), &spamWords, &numSpamWords);

    // Test the spam detection system on a new message
    char *newMessage = "Hello, just wanted to touch base about that project we talked about.";
    double probability = getSpamProbability(newMessage, spamWords, numSpamWords);
    printf("Probability that message is spam: %f\n", probability);

    // Clean up the spam words array
    free(spamWords);

    return 0;
}