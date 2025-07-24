//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: automated
#include <stdio.h>

void printLetter(char letter)
{
    switch (letter)
    {
        case 'A':
            printf("  /\\  \n /  \\ \n/____\\\n");
            break;
        case 'B':
            printf(" ____ \n| __ \\ \n| ___ \\\n|______|\n");
            break;
        case 'C':
            printf("  ___ \n / __\\\n/ /   \n\\ \\___\n \\____\\\n");
            break;
        case 'D':
            printf(" ____ \n|  _ \\ \n| |_) |\n|____/\n");
            break;
        case 'E':
            printf(" _____\n| ____|\n| |__  \n|___ \\ \n|____/ \n");
            break;
        case 'F':
            printf(" _____\n| ____|\n| |__  \n|___ \\ \n|    \\\n");
            break;
        // add the rest of the letters here
        default:
            printf("      \n      \n      \n      \n      \n");
    }
}

int main()
{
    char str[100];
    printf("Enter the text: ");
    scanf("%s", str);
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        printLetter(str[i]);
    }
    
    return 0;
}