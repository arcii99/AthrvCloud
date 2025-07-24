//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[50];
    int length, lower = 0, upper = 0, digits = 0, special = 0, strength = 0;

    printf("Welcome to the Password Strength Checker!\n");
    printf("Enter your password: ");
    fgets(password, 50, stdin);
    length = strlen(password) - 1; // exclude newline character

    for(int i = 0; i < length; i++)
    {
        char c = password[i];
        if(islower(c))
            lower++;
        else if(isupper(c))
            upper++;
        else if(isdigit(c))
            digits++;
        else
            special++;
    }

    if(length >= 8 && length <= 16)
        strength++;
    if(lower > 0 && upper > 0)
        strength++;
    if(digits > 0)
        strength++;
    if(special > 0)
        strength++;

    printf("\nPassword strength: ");

    switch(strength)
    {
        case 0:
            printf("Very weak\n");
            break;
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Fair\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        case 4:
            printf("Very strong\n");
            break;
        default:
            printf("Error\n");
    }

    return 0;
}