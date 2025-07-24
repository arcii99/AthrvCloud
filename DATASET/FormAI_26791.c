//FormAI DATASET v1.0 Category: Spam Detection System ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100 // maximum length for user input message
#define SPAM_THRESHOLD 0.3 // threshold for spam detection

int main()
{
    char message[MAX_INPUT_LENGTH]; // user input message
    int spam_count = 0; // counter for spam words found
    char* spam_words[] = {"buy", "now", "discount", "sale", "limited", "offer"}; // list of spam words to check for

    printf("Enter a message: ");
    fgets(message, MAX_INPUT_LENGTH, stdin); // get user input

    for(int i = 0; i < strlen(message); i++) // loop through each character in the message
    {
        for(int j = 0; j < sizeof(spam_words)/sizeof(spam_words[0]); j++) // loop through each spam word
        {
            if(strncmp(&message[i], spam_words[j], strlen(spam_words[j])) == 0) // check if message contains spam word
            {
                spam_count++; // increment spam count
            }
        }
    }

    float spam_score = (float)spam_count / strlen(message); // calculate spam score

    if(spam_score >= SPAM_THRESHOLD) // check if spam score exceeds threshold
    {
        printf("Warning: possible spam message\n");
    }
    else
    {
        printf("Message okay\n");
    }

    return 0;
}