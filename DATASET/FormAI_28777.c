//FormAI DATASET v1.0 Category: Spam Detection System ; Style: relaxed
// C Spam Detection System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MSG_LEN 1000    // Maximum length of a message
#define SPAM_THRESHOLD 3    // Frequency threshold for identifying spam
#define NUM_MSGS 10         // Number of messages to test

// Structure to represent a message with its frequency count
typedef struct {
    char msg[MAX_MSG_LEN];
    int freqCount;
} Message;

// Function to check if a message is spam
bool isSpam(Message msg) {
    return (msg.freqCount >= SPAM_THRESHOLD);
}

int main() {
    // Create an array of messages and their frequency count
    Message messages[NUM_MSGS] = { 
        {"Buy now and save 50%", 5},
        {"Click here for free money!", 7},
        {"You have won a lottery!", 10},
        {"Enlarge your body part!", 2},
        {"Meet singles in your area!", 1},
        {"Earn $1000 per day!", 4},
        {"Get a free iPhone now!", 3},
        {"Be your own boss!", 0},
        {"Limited time offer!", 0},
        {"Congratulations, you have won!", 6}
    };
    int totalSpam = 0;  // Counter for the total number of spam messages
    
    // Loop through all messages and check if they are spam
    for (int i = 0; i < NUM_MSGS; i++) {
        if (isSpam(messages[i])) {
            totalSpam++;
            printf("%s - This message is spam.\n", messages[i].msg);
        }
        else {
            printf("%s - This message is not spam.\n", messages[i].msg);
        }
    }
    
    // Print the total number of spam messages found
    printf("\n%d out of %d messages are spam.\n", totalSpam, NUM_MSGS);
    
    return 0;
}