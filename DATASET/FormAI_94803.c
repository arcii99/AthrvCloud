//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: random
#include<stdio.h>
#include<string.h>

void printLetter(char letter);
void printSpace(int numSpaces);

int main()
{
    char text[100];
    printf("Enter some text: ");
    fgets(text, 100, stdin);
    int len = strlen(text);
    for(int i = 0; i < len; i++)
    {
        printLetter(text[i]);
    }
    return 0;
}

void printLetter(char letter)
{
    switch(letter)
    {
        case 'A': 
            printf("  /\\    \n /  \\   \n/____\\  \n/    \\  \n\n");
            break;
        case 'B':
            printf(" ____   \n|    \\  \n|____/  \n|    \\  \n|____/  \n\n");
            break;
        case 'C':
            printf("  ____  \n /     \\ \n/       \\\n\\       /\n \\_____/\n\n");
            break;
        case 'D':
            printf(" ____   \n|    \\  \n|     \\ \n|     / \n|____/  \n\n");
            break;
        case 'E':
            printf(" _____  \n|      \n|_____ \n|      \n|_____ \n\n");
            break;
        // continue with the remaining letters...
        default:
            printSpace(5);
            break;
    }
}

void printSpace(int numSpaces)
{
    for(int i = 0; i < numSpaces; i++)
    {
        printf(" ");
    }
    printf("\n\n");
}