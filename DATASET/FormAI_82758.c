//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <string.h>

int main()
{
    char email[100];
    int spam = 0; //initializing variable to check for spam

    printf("Enter your email address: ");
    scanf("%s", email);

    //checking for unwanted words in the email
    if (strstr(email, "money") || strstr(email, "free") || strstr(email, "lottery"))
    {
        spam = 1; //set spam variable to 1 if unwanted word found
    }

    //checking for the "@" symbol 
    if (!(strstr(email,"@")))
    {
        spam = 1; //set spam variable to 1 if "@" not found
    }

    if(spam == 1)
    {
        printf("Your Email is identified as spam! \n");
    }
    else
    {
        printf("Your Email is identified as non-spam! \n");
    }
    
    return 0;
}