//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: modular
#include <stdio.h>
#include <string.h>

// Function prototypes
void greeting();
void translate(char[]);
void farewell();

int main()
{
    char message[100];

    greeting();
    printf("Enter your message in the C Alien language: ");
    fgets(message, 100, stdin);
    translate(message);
    farewell();

    return 0;
}

void greeting()
{
    printf("Welcome to the C Alien Language Translator!\n\n");
}

void translate(char message[])
{
    int i;
    char output[100];

    for(i = 0; i < strlen(message); i++)
    {
        switch(message[i])
        {
            case 'C':
                strcat(output, "G");
                break;
            case 'A':
                strcat(output, "T");
                break;
            case 'T':
                strcat(output, "C");
                break;
            case 'G':
                strcat(output, "A");
                break;
            default:
                strcat(output, "?");
                break;
        }
    }

    printf("Translation: %s\n", output);
}

void farewell()
{
    printf("\nThank you for using the C Alien Language Translator!\n");
}