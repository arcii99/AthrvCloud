//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
#include <stdio.h>
#include <string.h>

int main()
{
    char msg[100], morseCode[100][100], morseChar, ch;
    int i, j, k;

    printf("Enter the message you want to convert to Morse Code: ");
    fgets(msg, 100, stdin);

    // Converting the message to Morse Code
    for (i = 0; i < strlen(msg); i++)
    {
        ch = toupper(msg[i]);

        switch (ch)
        {
            case 'A':
                strcpy(morseCode[i], ".-");
                break;

            case 'B':
                strcpy(morseCode[i], "-...");
                break;

            case 'C':
                strcpy(morseCode[i], "-.-.");
                break;

            case 'D':
                strcpy(morseCode[i], "-..");
                break;

            case 'E':
                strcpy(morseCode[i], ".");
                break;

            case 'F':
                strcpy(morseCode[i], "..-.");
                break;

            case 'G':
                strcpy(morseCode[i], "--.");
                break;

            case 'H':
                strcpy(morseCode[i], "....");
                break;

            case 'I':
                strcpy(morseCode[i], "..");
                break;

            case 'J':
                strcpy(morseCode[i], ".---");
                break;

            case 'K':
                strcpy(morseCode[i], "-.-");
                break;

            case 'L':
                strcpy(morseCode[i], ".-..");
                break;

            case 'M':
                strcpy(morseCode[i], "--");
                break;

            case 'N':
                strcpy(morseCode[i], "-.");
                break;

            case 'O':
                strcpy(morseCode[i], "---");
                break;

            case 'P':
                strcpy(morseCode[i], ".--.");
                break;

            case 'Q':
                strcpy(morseCode[i], "--.-");
                break;

            case 'R':
                strcpy(morseCode[i], ".-.");
                break;

            case 'S':
                strcpy(morseCode[i], "...");
                break;

            case 'T':
                strcpy(morseCode[i], "-");
                break;

            case 'U':
                strcpy(morseCode[i], "..-");
                break;

            case 'V':
                strcpy(morseCode[i], "...-");
                break;

            case 'W':
                strcpy(morseCode[i], ".--");
                break;

            case 'X':
                strcpy(morseCode[i], "-..-");
                break;

            case 'Y':
                strcpy(morseCode[i], "-.--");
                break;

            case 'Z':
                strcpy(morseCode[i], "--..");
                break;

            case '0':
                strcpy(morseCode[i], "-----");
                break;

            case '1':
                strcpy(morseCode[i], ".----");
                break;

            case '2':
                strcpy(morseCode[i], "..---");
                break;

            case '3':
                strcpy(morseCode[i], "...--");
                break;

            case '4':
                strcpy(morseCode[i], "....-");
                break;

            case '5':
                strcpy(morseCode[i], ".....");
                break;

            case '6':
                strcpy(morseCode[i], "-....");
                break;

            case '7':
                strcpy(morseCode[i], "--...");
                break;

            case '8':
                strcpy(morseCode[i], "---..");
                break;

            case '9':
                strcpy(morseCode[i], "----.");
                break;

            case ' ':
                strcpy(morseCode[i], "/");
                break;

            default:
                // handling unsupported characters
                printf("\nSorry, we do not support the character: %c", ch);
        }
    }

    // Printing the Morse Code message
    printf("\nMorse Code: ");
    for (i = 0; i < strlen(msg); i++)
    {
        for (j = 0; morseCode[i][j] != '\0'; j++)
        {
            printf("%c", morseCode[i][j]);
        }
        printf(" ");
    }

    return 0;
}