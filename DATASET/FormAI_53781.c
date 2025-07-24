//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convert(char*);

int main()
{
    char input[100];
    printf("Enter a phrase to convert to Morse code: ");
    scanf("%[^\n]", input);
    convert(input);
    return 0;
}

void convert(char* message)
{
    printf("\nMorse code output:\n");
    for(int i=0; message[i]!='\0'; i++)
    {
        switch (toupper(message[i]))
        {
            case 'A':
                printf(".- ");
                break;
            case 'B':
                printf("-... ");
                break;
            case 'C':
                printf("-.-. ");
                break;
            case 'D':
                printf("-.. ");
                break;
            case 'E':
                printf(". ");
                break;
            case 'F':
                printf("..-. ");
                break;
            case 'G':
                printf("--. ");
                break;
            case 'H':
                printf(".... ");
                break;
            case 'I':
                printf(".. ");
                break;
            case 'J':
                printf(".--- ");
                break;
            case 'K':
                printf("-.- ");
                break;
            case 'L':
                printf(".-.. ");
                break;
            case 'M':
                printf("-- ");
                break;
            case 'N':
                printf("-. ");
                break;
            case 'O':
                printf("--- ");
                break;
            case 'P':
                printf(".--. ");
                break;
            case 'Q':
                printf("--.- ");
                break;
            case 'R':
                printf(".-. ");
                break;
            case 'S':
                printf("... ");
                break;
            case 'T':
                printf("- ");
                break;
            case 'U':
                printf("..- ");
                break;
            case 'V':
                printf("...- ");
                break;
            case 'W':
                printf(".-- ");
                break;
            case 'X':
                printf("-..- ");
                break;
            case 'Y':
                printf("-.-- ");
                break;
            case 'Z':
                printf("--.. ");
                break;
            case ' ':
                printf("/ ");
                break;
            default:
                break;
        }
    }
    printf("\n");
}