//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Welcome to the Spam Detection System!\n");
    printf("Please enter your message: ");

    char message[200];
    fgets(message, 200, stdin); // read in user message

    // checking for spam
    int uppercase_count = 0;
    int lowercase_count = 0;
    int exclamation_count = 0;
    int dollar_count = 0;

    for(int i = 0; i < strlen(message); i++)
    {
        if(message[i] >= 'A' && message[i] <= 'Z') // checking for uppercase letters
        {
            uppercase_count++;
        }
        else if(message[i] >= 'a' && message[i] <= 'z') // checking for lowercase letters
        {
            lowercase_count++;
        }
        else if(message[i] == '!') // checking for exclamation points
        {
            exclamation_count++;
        }
        else if(message[i] == '$') // checking for dollar signs
        {
            dollar_count++;
        }
    }

    if(uppercase_count > 5 || lowercase_count > 10 || exclamation_count > 2 || dollar_count > 0)
    {
        printf("Warning: Your message may be classified as spam!\n");
    }
    else
    {
        printf("No spam detected. Message approved!\n");
    }

    return 0;
}