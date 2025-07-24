//FormAI DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h> // Standard Input Output Library
#include <string.h> // String Library

void analyzeMessage(char message[]) {

    // Counters for different spam categories
    int wordCount = 0;
    int linkCount = 0;
    int excessiveCaps = 0;
    int emoticonCount = 0;

    // Split words by whitespace
    char *token = strtok(message, " ");
    while (token != NULL) {
        // Count the number of words
        wordCount++;

        // Check if word contains a link
        if (strstr(token, "http://")) {
            linkCount++;
        }

        // Check if word has excessive capital letters
        int capsCount = 0;
        for (int i = 0; i < strlen(token); i++) {
            if (token[i] >= 'A' && token[i] <= 'Z') {
                capsCount++;
            }
        }
        if ((float)capsCount / strlen(token) >= 0.5) {
            excessiveCaps++;
        }

        // Check for emoticons
        if (strstr(token, ":)") || strstr(token, ";)") || strstr(token, ":D")) {
            emoticonCount++;
        }

        // Move on to next word
        token = strtok(NULL, " ");
    }

    // Determine if message is spam
    if (wordCount >= 10 && linkCount + emoticonCount >= 2) {
        printf("This message is spam.\n");
    } else if (excessiveCaps >= 3) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

}

int main() {

    // Example messages to analyze
    char message1[] = "Hey, how are you doing? :)";
    analyzeMessage(message1); // Not spam

    char message2[] = "WIN FREE MONEY BY CLICKING HERE!";
    analyzeMessage(message2); // Spam

    char message3[] = "HELLOOOOO HAVE A GOOD DAY :D";
    analyzeMessage(message3); // Spam

    char message4[] = "Check out my new blog post http://example.com";
    analyzeMessage(message4); // Not spam

    return 0;
}