//FormAI DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <string.h>

#define SPAM_THRESHOLD 5 // Minimum number of spam words to classify a message as spam

// Spam words to look out for
char spam_words[6][20] = {"viagra", "lottery", "win", "earn", "money", "enlarge"};

// Function to count number of occurrences of a spam word in a given message
int count_spam(char message[], char spam_word[])
{
    int counter = 0;
    char *word = strtok(message, " "); // Split message into words
    
    // Loop through each word and compare with spam word
    while (word != NULL)
    {
        if (strcmp(word, spam_word) == 0)
        {
            counter++;
        }
        word = strtok(NULL, " ");
    }
    
    return counter;
}

// Function to classify message as spam or not
int is_spam(char message[])
{
    int spam_count = 0;
    
    // Loop through each spam word and count occurrences in the message
    for (int i = 0; i < 6; i++)
    {
        spam_count += count_spam(message, spam_words[i]);
    }
    
    // If spam count is above the threshold, message is classified as spam
    if (spam_count >= SPAM_THRESHOLD)
    {
        return 1;
    }
    
    return 0;
}

int main()
{
    // Get user input for message
    printf("Enter your message: ");
    char message[100];
    fgets(message, 100, stdin);
    
    // Remove newline character from fgets
    message[strcspn(message, "\n")] = 0;
    
    // Check if message is spam
    if (is_spam(message))
    {
        printf("This message is classified as spam.\n");
    }
    else
    {
        printf("This message is not classified as spam.\n");
    }
    
    return 0;
}