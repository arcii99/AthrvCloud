//FormAI DATASET v1.0 Category: Spam Detection System ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main()
{
    int spam_count = 0;
    char message[100];

    printf("Enter your message: ");
    fgets(message, 100, stdin);

    char* spams[] = {"buy", "sell", "discount", "offer", "promotion"};
    int i, j, spam_check;

    for (i = 0; i < strlen(message); i++) 
    {
        // Iterate through each word in message
        if (message[i] == ' ') 
        {
            // Store the word in a temporary variable
            char temp[20];
            int k = 0;
            for (j = i + 1; message[j] != ' ' && message[j] != '\n'; j++) 
            {
                temp[k++] = message[j];
            }
            temp[k] = '\0';

            // Check if the word is a spam
            spam_check = 0;
            for (j = 0; j < 5; j++) 
            {
                if (strcmp(temp, spams[j]) == 0) 
                {
                    spam_count++;
                    spam_check = 1;
                    break;
                }
            }

            // If spam is detected, replace it with asterisks
            if (spam_check == 1) 
            {
                for (j = i + 1; message[j] != ' ' && message[j] != '\n'; j++) 
                {
                    message[j] = '*';
                }
            }
        }
    }

    printf("Your message: %s", message);

    if (spam_count > 0) 
    {
        printf("Warning: %d spam word(s) detected.", spam_count);
    } 
    else 
    {
        printf("No spam detected.");
    }

    return 0;
}