//FormAI DATASET v1.0 Category: Spam Detection System ; Style: energetic
//Welcome to the Spam Detection System!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[1000], word[100], spamWords[15][30] = {"sale", "discount", "cash prize", "free", "winner", 
                                                        "limited time offer", "act now", "call now", "order now", 
                                                        "money back guarantee", "profits", "earn", "incredible offer", "exclusive deal"};

    int i, j, spamCount = 0;

    printf("Enter the message you want to check for spam:\n");
    fgets(message, 1000, stdin); //getting user input using fgets

    //checking for spam words in the message
    for(i = 0; message[i] != '\0'; i++)
    {
        j = 0;
        while(message[i] != ' ' && message[i] != '\n') //checking for word boundaries
        {
            word[j++] = message[i++];
        }
        word[j] = '\0';
        for(j = 0; j < 15; j++) //comparing the word with spam words
        {
            if(strcmp(word, spamWords[j]) == 0)
            {
                spamCount++; //if match found, count as spam word
                break;
            }
        }
    }

    if(spamCount == 0)
    {
        printf("Your message is not a spam!");
    }
    else
    {
        printf("Your message contains %d spam word(s) and is identified as spam!", spamCount);
    }

 return 0;
}