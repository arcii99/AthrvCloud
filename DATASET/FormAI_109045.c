//FormAI DATASET v1.0 Category: Text processing ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to check for unsafe characters
int checkUnsafeChars(char c)
{
    switch(c)
    {
        case '&':
        case '<':
        case '>':
        case '"':
        case '\'':
            return 1;
        default:
            return 0;
    }
}

int main()
{
    char text[1000];
    printf("Enter some text:\n");
    fgets(text, 1000, stdin);
    printf("You entered: %s\n", text);

    //Let's check for unsafe characters in entered text
    int i;
    for(i=0; i<strlen(text); i++)
    {
        if(checkUnsafeChars(text[i]))
        {
            printf("Unsafe character found in text!\n");
            exit(1);    //Exiting program if unsafe character found
        }
    }

    //If program reaches here, text is safe, so let's process it
    printf("Text is safe, processing it...\n");

    //Processing code goes here

    return 0;
}