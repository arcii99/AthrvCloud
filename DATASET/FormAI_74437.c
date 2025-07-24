//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *text_to_morse_code(char *text);

int main()
{
    printf("Welcome to the Grateful Morse Code Converter!\n");
    printf("Enter the text you want to convert to Morse code: ");

    char text[100];
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("\nHere is the Morse code for your text:\n");
    printf("%s\n", text_to_morse_code(text));

    printf("Thank you for using the Grateful Morse Code Converter!\n");

    return 0;
}

char *text_to_morse_code(char *text)
{
    static char morse_code[1000];

    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            strcat(morse_code, " / ");
        }
        else if (isalpha(text[i]))
        {
            switch (toupper(text[i]))
            {
                case 'A':
                    strcat(morse_code, ".- ");
                    break;
                case 'B':
                    strcat(morse_code, "-... ");
                    break;
                case 'C':
                    strcat(morse_code, "-.-. ");
                    break;
                case 'D':
                    strcat(morse_code, "-.. ");
                    break;
                case 'E':
                    strcat(morse_code, ". ");
                    break;
                case 'F':
                    strcat(morse_code, "..-. ");
                    break;
                case 'G':
                    strcat(morse_code, "--. ");
                    break;
                case 'H':
                    strcat(morse_code, ".... ");
                    break;
                case 'I':
                    strcat(morse_code, ".. ");
                    break;
                case 'J':
                    strcat(morse_code, ".--- ");
                    break;
                case 'K':
                    strcat(morse_code, "-.- ");
                    break;
                case 'L':
                    strcat(morse_code, ".-.. ");
                    break;
                case 'M':
                    strcat(morse_code, "-- ");
                    break;
                case 'N':
                    strcat(morse_code, "-. ");
                    break;
                case 'O':
                    strcat(morse_code, "--- ");
                    break;
                case 'P':
                    strcat(morse_code, ".--. ");
                    break;
                case 'Q':
                    strcat(morse_code, "--.- ");
                    break;
                case 'R':
                    strcat(morse_code, ".-. ");
                    break;
                case 'S':
                    strcat(morse_code, "... ");
                    break;
                case 'T':
                    strcat(morse_code, "- ");
                    break;
                case 'U':
                    strcat(morse_code, "..- ");
                    break;
                case 'V':
                    strcat(morse_code, "...- ");
                    break;
                case 'W':
                    strcat(morse_code, ".-- ");
                    break;
                case 'X':
                    strcat(morse_code, "-..- ");
                    break;
                case 'Y':
                    strcat(morse_code, "-.-- ");
                    break;
                case 'Z':
                    strcat(morse_code, "--.. ");
                    break;
            }
        }
    }

    return morse_code;
}