//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include<stdio.h>
#include<string.h>

int main()
{
    char password[50];
    int length, i, uppercase, lowercase, digits, symbol, strength = 0;

    printf("Welcome to Password Strength Checker!\n\n");
    printf("Please enter your password: ");
    scanf("%s", password);

    length = strlen(password); // calculating length

    for(i=0; i<length; i++)
    {
        if(password[i]>='A'&&password[i]<='Z') // checking for uppercase letters
            uppercase = 1;

        if(password[i]>='a'&&password[i]<='z') // checking for lowercase letters
            lowercase = 1;

        if(password[i]>='0'&&password[i]<='9') // checking for digits
            digits = 1;

        if((password[i]>='!'&&password[i]<='/')||(password[i]>=':'&&password[i]<='@')||(password[i]>='['&&password[i]<='`')||(password[i]>='{'&&password[i]<='~')) // checking for symbols
            symbol = 1; 
    }

    strength = uppercase + lowercase + digits + symbol; // adding the number of characters found

    printf("\nYour password strength: ");

    switch(strength)
    {
        case 4: printf("Strong\n"); break;
        case 3: printf("Moderate\n"); break;
        case 2: printf("Weak\n"); break;
        case 1: printf("Very Weak\n"); break;
        default: printf("Undefined\n"); break;
    }

    return 0;
}