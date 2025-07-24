//FormAI DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100 //Maximum size of the input string

int check_spam(char *str) //Function to check for spam
{
    char *spam_keywords[] = {"money", "lottery", "viagra", "earn", "cash", "free", "sex", "make", "income"}; //List of spam keywords
    int i, found;
    char str_copy[MAX_SIZE];
    strcpy(str_copy, str); //Create a copy of the input string

    for(i = 0; i < strlen(str_copy); i++) //Convert the string to lowercase
    {
        str_copy[i] = tolower(str_copy[i]);
    }

    found = 0; //Initialize found flag

    for(i = 0; i < sizeof(spam_keywords) / sizeof(spam_keywords[0]); i++) //Loop through the list of spam keywords
    {
        if(strstr(str_copy, spam_keywords[i]) != NULL) //If keyword is found in the string
        {
            found = 1; //Set found flag
            break;
        }
    }

    return found; //Return the found flag
}

int main()
{
    char input_str[MAX_SIZE];
    int spam;
    
    printf("Enter a string: ");
    fgets(input_str, MAX_SIZE, stdin); //Read input string from user
    
    spam = check_spam(input_str); //Check for spam
    
    if(spam)
    {
        printf("Warning: This message may be spam.\n");
    }
    else
    {
        printf("This message is not spam.\n");
    }

    return 0;
}