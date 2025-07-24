//FormAI DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 1000
#define MAX_MESSAGE_LEN 255
#define SPAM_THRESHOLD 0.8

int num_messages = 0;
char messages[MAX_MESSAGES][MAX_MESSAGE_LEN];

int is_spam(char* message)
{
    int num_spam_words = 0;
    char* word = strtok(message, " ,.!?");
    
    while (word != NULL)
    {
        if (strcmp(word, "viagra") == 0 || strcmp(word, "win") == 0 || strcmp(word, "money") == 0)
        {
            num_spam_words++;
        }
        
        word = strtok(NULL, " ,.!?");
    }
    
    double spam_ratio = (double)num_spam_words / (double)strlen(message);
    
    if (spam_ratio > SPAM_THRESHOLD)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void add_message(char* message)
{
    if (num_messages >= MAX_MESSAGES)
    {
        printf("Max number of messages reached\n");
    }
    else
    {
        strcpy(messages[num_messages], message);
        num_messages++;
    }
}

int main()
{
    char input[MAX_MESSAGE_LEN];
    
    while (1)
    {
        printf("Enter a message: ");
        fgets(input, MAX_MESSAGE_LEN, stdin);
        input[strcspn(input, "\n")] = '\0';
        
        if (is_spam(input))
        {
            printf("SPAM detected!\n");
        }
        else
        {
            add_message(input);
            printf("Message added to database\n");
        }
    }
    
    return 0;
}