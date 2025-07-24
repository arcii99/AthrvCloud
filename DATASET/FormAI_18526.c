//FormAI DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100 

int main()
{
    char email[MAX_LEN];
    int i,atpos=0,dotpos=0,count=0;

    printf("Please enter your email address: ");
    fgets(email, MAX_LEN, stdin);

    //Checking for the @ symbol
    for(i=0; i<strlen(email); i++)
    {
        if(email[i] == '@')
            atpos = i;
    }

    //Checking for the period
    for(i=atpos; i<strlen(email); i++)
    {
        if(email[i] == '.')
            dotpos = i;
    }

    //Calculating the length of the username
    for(i=0; i<atpos; i++)
    {
        if(email[i] != ' ')
            count++;       
    }

    //Checking if the length of the username is greater than zero
    if(count == 0)
    {
        printf("Invalid Email Address: Please enter a valid email address.\n");
        return 0;
    }

    //Checking if the @ symbol is present
    if(atpos == 0)
    {
        printf("Invalid Email Address: Please enter a valid email address.\n");
        return 0;
    }

    //Checking if the period is present
    if(dotpos == 0)
    {
        printf("Invalid Email Address: Please enter a valid email address.\n");
        return 0;
    }

    //Checking if the period is present after the @ symbol
    if(dotpos < atpos)
    {
        printf("Invalid Email Address: Please enter a valid email address.\n");
        return 0;
    }

    printf("Valid Email Address: Email address entered successfully!\n");

    return 0;
}