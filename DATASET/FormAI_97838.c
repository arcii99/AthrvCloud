//FormAI DATASET v1.0 Category: String manipulation ; Style: random
//A unique string manipulation program using ASCII art
//By Chatbot
#include <stdio.h>
#include <string.h>

int main()
{
    //define the string to be manipulated
    char message[] = "Hello Friends! I am a chatbot!";

    //get the length of the message string
    int length = strlen(message);

    //display the length of the message string in ASCII art
    printf("   /\\   \n");
    printf("  /  \\  \n");
    printf(" /    \\ \n");
    printf("/------\\\n");
    printf("|Length|\n");
    printf("|%6d|\n", length);
    printf("\\------/\n");
    printf(" \\    / \n");
    printf("  \\  /  \n");
    printf("   \\/   \n");

    //display the original message in ASCII art
    printf("   /\\   \n");
    printf("  /  \\  \n");
    printf(" /    \\ \n");
    printf("/------\\\n");
    printf("|Message|\n");
    printf("|%s|\n", message);
    printf("\\------/\n");
    printf(" \\    / \n");
    printf("  \\  /  \n");
    printf("   \\/   \n");

    //manipulate the message string by replacing the letter 'o' with the number '0'
    for (int i = 0; i < length; i++)
    {
        if (message[i] == 'o')
        {
            message[i] = '0';
        }
    }

    //display the manipulated message in ASCII art
    printf("   /\\      \n");
    printf("  /  \\     \n");
    printf(" /    \\    \n");
    printf("/--------\\\n");
    printf("|Manipulated|\n");
    printf("|%s|\n", message);
    printf("\\--------/\n");
    printf(" \\      / \n");
    printf("  \\    /  \n");
    printf("   \\/     \n");

    return 0;
}