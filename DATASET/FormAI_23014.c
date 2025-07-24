//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <string.h>

// Define maximum characters per message and number of messages to be analyzed
#define MAX_MSG_CHARS 1000
#define MAX_MSGS 10

// Define global variables for spam thresholds
float spamThreshold1 = 0.1; // Threshold for identifying generic spam messages
float spamThreshold2 = 0.8; // Threshold for identifying phishing messages

// Declare function to count occurrences of a given substring in a string
int countSubstring(char *str, char *sub);

int main() {
    // Declare variables for messages and message analysis results
    char messages[MAX_MSGS][MAX_MSG_CHARS];
    float spamProbabilities[MAX_MSGS];
    int i, j;
    
    // Ask user to input messages and store them in the messages array
    printf("Please enter %d messages (max. %d characters per message):\n", MAX_MSGS, MAX_MSG_CHARS);
    for (i=0; i<MAX_MSGS; i++) {
        printf("Message %d: ", i+1);
        fgets(messages[i], MAX_MSG_CHARS, stdin);
        
        // Remove newline character from user input
        if ((strlen(messages[i])>0) && (messages[i][strlen(messages[i])-1] == '\n')) {
            messages[i][strlen(messages[i])-1] = '\0';
        }
        
        // Calculate spam probability based on occurrence of certain keywords or patterns
        spamProbabilities[i] = 0;
        spamProbabilities[i] += (float) countSubstring(messages[i], "viagra") / strlen(messages[i]);
        spamProbabilities[i] += (float) countSubstring(messages[i], "cialis") / strlen(messages[i]);
        spamProbabilities[i] += (float) countSubstring(messages[i], "dating") / strlen(messages[i]);
        spamProbabilities[i] += (float) countSubstring(messages[i], "Nigerian prince") / strlen(messages[i]);
        if (strstr(messages[i], "https://") || strstr(messages[i], "http://")) {
            spamProbabilities[i] += 0.5;
        }
        if (strstr(messages[i], "Dear customer") || strstr(messages[i], "Dear account holder")) {
            spamProbabilities[i] += 0.8;
        }
        
        // Print spam probability for each message
        printf("Spam probability: %.2f\n", spamProbabilities[i]);
        printf("\n");
    }
    
    // Detect and print spam messages based on spam probability thresholds
    printf("SPAM DETECTION RESULTS:\n");
    for (i=0; i<MAX_MSGS; i++) {
        if (spamProbabilities[i] >= spamThreshold2) {
            printf("Message %d is highly likely to be a phishing message\n", i+1);
        }
        else if (spamProbabilities[i] >= spamThreshold1) {
            printf("Message %d is likely to be generic spam\n", i+1);
        }
        else {
            printf("Message %d appears to be legitimate\n", i+1);
        }
    }
    
    return 0;
}

// Function to count occurrences of a given substring in a string
int countSubstring(char *str, char *sub) {
    int count = 0;
    while ((str = strstr(str, sub))) {
        count++;
        str++;
    }
    return count;
}