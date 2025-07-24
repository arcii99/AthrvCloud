//FormAI DATASET v1.0 Category: Spam Detection System ; Style: modular
#include<stdio.h>
#include<string.h>

/* Function to detect spam */
int spam_detection(char message[]) {
    int spam_count = 0;
    char spam[] = "buy now";
    char *p = strstr(message, spam); // Check if the spam word exists in the message
    if (p != NULL) { // If it exists, add 1 to the spam count
        spam_count++;
    }
    return spam_count; // Return the spam count
}

/* Main function */
int main() {
    char message[100];
    int spam_count;

    printf("Enter your message: ");
    fgets(message, 100, stdin);  // Get the message from the user

    spam_count = spam_detection(message); // Call the function to detect spam

    if (spam_count == 0) { // If the spam count is 0, the message is not spam
        printf("This message is not spam.\n");
    }
    else { // If the spam count is greater than 0, the message is spam
        printf("This message is spam.\n");
    }

    return 0;
}