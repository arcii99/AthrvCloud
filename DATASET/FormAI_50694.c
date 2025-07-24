//FormAI DATASET v1.0 Category: Spam Detection System ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main()
{
    char spamWords[5][20] = {"money", "free", "congratulations", "offer", "click"}; // Our list of spam words
    char message[1000];
    int i, j, found;
    
    printf("Enter a message: ");
    scanf("%[^\n]%*c", message); // Allowing spaces in input
    
    char wordsInMessage[100][20]; // We will store each word in the message separately here
    int wordCount = 0;
    int messageLength = strlen(message);
    char tempWord[20];
    int tempWordIndex = 0;
    
    for(i=0; i<=messageLength; i++)
    {
        if(message[i]==' ' || message[i]=='\0') // If we reached a space or end of line.
        {
            tempWord[tempWordIndex] = '\0'; // Terminate the temp word with null character
            strcpy(wordsInMessage[wordCount], tempWord); // Copying the temp word to our array of words
            wordCount++;
            tempWordIndex = 0; // Resetting the index for the temp word
        }
        else
        {
            tempWord[tempWordIndex] = message[i];
            tempWordIndex++;
        }
    }
    
    found = 0;
    for(i=0; i<wordCount; i++)
    {
        for(j=0; j<5; j++) // Checking if any word in the message matches one of our spam words
        {
            if(strcmp(wordsInMessage[i], spamWords[j])==0)
            {
                found = 1;
                break;
            }
        }
        
        if(found==1) // If any spam word is found, break the loop and print the message is spam
        {
            printf("\n\nThe message is spam!\n");
            break;
        }
    }

    if(found==0) // If no spam word is found, print the message is not spam
        printf("\n\nThe message is not spam!\n");
    
    return 0;
}