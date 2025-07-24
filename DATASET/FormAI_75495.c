//FormAI DATASET v1.0 Category: Spam Detection System ; Style: excited
#include <stdio.h>
#include <string.h>

int main()
{
    char message[1000]; // Define a buffer to store the message

    printf("Enter your message: ");
    fgets(message, 1000, stdin); // Get the message from the user 
    message[strlen(message) - 1] = '\0'; // Remove the newline character from the end

    // Define an array of spam words to detect
    char spamWords[5][20] = {"buy", "discount", "free", "money", "offer"};

    // Loop through each word in the message
    char* word = strtok(message, " ");
    int spamCount = 0; // Keep track of how many spam words are in the message
    while (word != NULL)
    {
        // Check if the word is a spam word
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(word, spamWords[i]) == 0)
            {
                spamCount++;
            }
        }

        word = strtok(NULL, " ");
    }

    // If there are more than 2 spam words, the message is considered spam
    if (spamCount > 2)
    {
        printf("SPAM DETECTED!");
    }
    else
    {
        printf("Message is clean.");
    }

    return 0;
}