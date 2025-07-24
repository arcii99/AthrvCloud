//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the size of the alien language dictionary
#define ALIEN_DICTIONARY_SIZE 9

// Define the size of the random message to be generated
#define MAX_MESSAGE_SIZE 50

// Alien language dictionary
char alienDictionary[ALIEN_DICTIONARY_SIZE][10] = {
    "blorgon",
    "jiklop",
    "plurt",
    "freen",
    "nerk",
    "torg",
    "zorp",
    "glip",
    "wub"
};

void translateMessage(char *message) {
    // Split up the message into individual words
    char *word = strtok(message, " ");

    while (word != NULL) {
        // Generate a random index to select a random alien word
        int randomIndex = rand() % ALIEN_DICTIONARY_SIZE;

        // Replace current word with a random alien word
        strcpy(word, alienDictionary[randomIndex]);

        // Get the next word from the message
        word = strtok(NULL, " ");
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];

    // Seed the random number generator
    srand(time(0));

    printf("Enter your message in English:\n");

    // Get message input from the user
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    // Remove newline character from input
    message[strcspn(message, "\n")] = 0;

    // Translate the message to the alien language
    translateMessage(message);

    printf("Your message translated to the alien language:\n%s\n", message);

    return 0;
}