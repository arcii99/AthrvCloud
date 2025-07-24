//FormAI DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Spam words array
char *spamWords[] = {"Buy", "Sale", "Free", "Offer", "Discount", "Promotion"};

// Function to check spam words
bool isSpam(char *text)
{
    int i;
    char *token;
    
    // Splitting the text into words
    token = strtok(text, " ");
    
    while(token != NULL)
    {
        // Comparing each word with spamWords
        for(i = 0; i < 6; i++)
        {
            if(strcmp(token, spamWords[i]) == 0)
            {
                return true;
            }
        }
        
        token = strtok(NULL, " "); // Getting next word
    }
    
    return false;
}

// Main function
int main()
{
    char text[1000];
    
    // Taking input from user
    printf("Enter your text: ");
    fgets(text, 1000, stdin);
    
    // Checking if input is spam or not
    if(isSpam(text))
    {
        printf("SPAM DETECTED! Please do not use spam words in your text.\n");
    }
    else
    {
        printf("This message is not spam. Keep spreading positivity!\n");
    }
    
    return 0;
}