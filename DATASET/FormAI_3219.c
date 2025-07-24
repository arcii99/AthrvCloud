//FormAI DATASET v1.0 Category: Spam Detection System ; Style: medieval
#include <stdio.h>
#include <string.h>

#define SPAM_LIMIT 5 // A predefined limit on the number of spams
#define SPAM_VALUE 2 // Points given to a message if it's classified as spam

// Function to determine the spam score of a message
int spam_detection(char *message) {
    int score = 0;

    // Sample code for detecting spam keywords
    if (strstr(message, "discount") != NULL || strstr(message, "free") != NULL) {
        score += SPAM_VALUE;
    }

    return score;
}

int main() {
    char user_message[100];
    int spam_score = 0, total_score = 0;

    // Sample code for acquiring user input in a medieval manner
    printf("Hail, brave knight! What message dost thou wish to send?" 
    "\nSpeak truly, for my eyesight is not what it used to be.\n");
    fgets(user_message, 100, stdin);

    spam_score = spam_detection(user_message); // Get the spam score of the message
    total_score += spam_score; // Add the score to the total

    // Output a response appropriate for a medieval setting
    if (total_score >= SPAM_LIMIT) {
        printf("By the grace of the king, your message has been marked as SPAM!\n");
    } else {
        printf("Your message has safely reached its destination. Godspeed, brave knight!\n");
    }

    return 0;
}