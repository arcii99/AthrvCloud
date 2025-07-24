//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void printArt(char c);

int main()
{
    char input[100];

    printf("Enter any text: ");
    fgets(input, 100, stdin);

    printf("\nYour ASCII art is:\n\n");
    for(int i=0; i<strlen(input); i++)
    {
        if(isalpha(input[i]))
        {
            printArt(toupper(input[i]));
        }
        else
        {
            printf("\n\n");
        }
    }

    return 0;
}

void printArt(char c)
{
    switch(c)
    {
        case 'A':
            printf("      /\\      \n");
            printf("     /  \\     \n");
            printf("    /    \\    \n");
            printf("   /______\\   \n");
            printf("  /        \\  \n");
            printf(" /          \\ \n");
            printf("/            \\\n\n");
            break;

        case 'B':
            printf(" ________   \n");
            printf("|        \\  \n");
            printf("|         | \n");
            printf("|________/  \n");
            printf("|         \\ \n");
            printf("|          |\n");
            printf("|________/ \n\n");
            break;

        case 'C':
            printf("    _______ \n");
            printf("   /        \n");
            printf("  /         \n");
            printf(" /          \n");
            printf(" \\          \n");
            printf("  \\         \n");
            printf("    \\_____  \n\n");
            break;

        //Add more cases for more letters

        default:
            printf("\n\n");
            break;
    }
}