//FormAI DATASET v1.0 Category: Spam Detection System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 1000 // maximum message length
#define SPAM_THRESHOLD 0.2 // percentage of spammy words to consider as spam

int main()
{
    char spam_words[10][20] = {"buy", "cheap", "free", "limited", "promotion", "discount", "offer", "click", "win", "cash"};
    // list of spammy words

    char message[MAX_MSG_LENGTH];
    printf("Enter message: ");
    fgets(message, MAX_MSG_LENGTH, stdin); // read input message from user

    int word_count = 0;
    float spam_count = 0;

    char *word = strtok(message, " ");
    while (word)
    {
        for (int i = 0; i < 10; i++)
        {
            if (strcmp(word, spam_words[i]) == 0)
            {
                spam_count++;
                break;
            }
        }
        word_count++;
        word = strtok(NULL, " ");
    }

    printf("Spam percentage: %f\n", spam_count/word_count);

    if ((spam_count/word_count) >= SPAM_THRESHOLD)
    {
        printf("This message is spam.\n");
    }
    else
    {
        printf("This message is not spam.\n");
    }

    return 0;
}