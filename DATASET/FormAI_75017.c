//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a letter to Morse Code
void convertToMorse(char letter)
{
    switch (toupper(letter))
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
        case '0':
            printf("----- ");
            break;
        case '1':
            printf(".---- ");
            break;
        case '2':
            printf("..--- ");
            break;
        case '3':
            printf("...-- ");
            break;
        case '4':
            printf("....- ");
            break;
        case '5':
            printf("..... ");
            break;
        case '6':
            printf("-.... ");
            break;
        case '7':
            printf("--... ");
            break;
        case '8':
            printf("---.. ");
            break;
        case '9':
            printf("----. ");
            break;
        default:
            printf(" "); // If it's not a letter or number, default to single space
            break;
    }
}

int main()
{
    printf("Welcome to our Morse Code Conversion program!\n");

    // Prompt user for input
    printf("Please enter the text you would like to convert:\n");
    char input[100];
    fgets(input, sizeof(input), stdin);

    printf("You entered: %s", input);

    printf("Converting to Morse Code...\n");

    // Loop through each character in input string
    for (int i = 0; i < strlen(input); i++)
    {
        convertToMorse(input[i]);
    }

    printf("\n\nThank you for using our program! Happy Morse Coding!\n");

    return 0;
}