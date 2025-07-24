//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Sherlock Holmes
//The Adventure of the C Password Strength Checker
//Written by Sherlock Holmes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[20];
    int length = 0;
    int uppercase = 0;
    int lowercase = 0;
    int numbers = 0;
    int symbols = 0;

    printf("Greetings! I see you need a password checked.\n");
    printf("Please enter your password: ");
    fgets(password, 20, stdin);

    //removing the newline character at the end of the input
    password[strcspn(password, "\n")] = 0;
    length = strlen(password);

    printf("Let me take a look.\n");

    for(int i = 0; i < length; i++)
    {
        char ch = password[i];
        if(isupper(ch))
        {
            uppercase++;
        }
        else if(islower(ch))
        {
            lowercase++;
        }
        else if(isdigit(ch))
        {
            numbers++;
        }
        else
        {
            symbols++;
        }
    }

    printf("\n");
    printf("After analyzing every nook and cranny of your password, I've determined the following:\n\n");

    if(length >= 8 && symbols >= 1 && numbers >= 1 && uppercase >= 1 && lowercase >= 1)
    {
        printf("Excellent! Your password certainly meets all the criteria!\n");
        printf("I must say, you appear to be quite knowledgeable about password security. Well done!\n");
    }
    else if(length >= 8 && (symbols >= 1 || numbers >= 1) && uppercase >= 1 && lowercase >= 1)
    {
        printf("Not bad, not bad at all. Your password meets most of the criteria, but could use a bit of improvement.\n");
        printf("I would suggest adding some numbers or symbols to further strengthen your password's security.\n");
    }
    else if(length >= 8 && uppercase >= 1 && lowercase >= 1)
    {
        printf("Your password is decent, but it could definitely use some work.\n");
        printf("I would highly recommend adding some numbers or symbols to increase the complexity of your password.\n");
    }
    else if(length < 8)
    {
        printf("I'm afraid your password doesn't meet the minimum length requirement of 8 characters.\n");
        printf("Don't worry, I won't fault you for this. Just be sure to choose a longer password in the future.\n");
    }
    else
    {
        printf("I'm sorry to say, your password could use quite a bit of work.\n");
        printf("It's important to have a strong password, especially in today's digital age.\n");
        printf("I highly recommend you choose a new password that meets all the criteria I mentioned earlier.\n");
    }

    printf("\n");
    printf("Thank you for giving me the opportunity to assist you. Stay safe and secure out there!\n");
    return 0;
}