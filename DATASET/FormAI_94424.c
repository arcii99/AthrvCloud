//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: cheerful
#include <stdio.h>
#include <string.h>

void dot();
void dash();

int main()
{
    char input[100], morse[100][100];
    int i, j, k, length;

    printf("Welcome to the cheerful C Text to Morse code conversion program!\n\n");
    printf("Please enter the text you would like to convert to Morse code: ");
    gets(input);

    length = strlen(input);
    for(i = 0; i < length; i++)
    {
        switch(input[i])
        {
            case 'a':
            case 'A':
                strcpy(morse[i], ".-");
                break;

            case 'b':
            case 'B':
                strcpy(morse[i], "-...");
                break;

            case 'c':
            case 'C':
                strcpy(morse[i], "-.-.");
                break;

            case 'd':
            case 'D':
                strcpy(morse[i], "-..");
                break;

            case 'e':
            case 'E':
                strcpy(morse[i], ".");
                break;

            case 'f':
            case 'F':
                strcpy(morse[i], "..-.");
                break;

            case 'g':
            case 'G':
                strcpy(morse[i], "--.");
                break;

            case 'h':
            case 'H':
                strcpy(morse[i], "....");
                break;

            case 'i':
            case 'I':
                strcpy(morse[i], "..");
                break;

            case 'j':
            case 'J':
                strcpy(morse[i], ".---");
                break;

            case 'k':
            case 'K':
                strcpy(morse[i], "-.-");
                break;

            case 'l':
            case 'L':
                strcpy(morse[i], ".-..");
                break;

            case 'm':
            case 'M':
                strcpy(morse[i], "--");
                break;

            case 'n':
            case 'N':
                strcpy(morse[i], "-.");
                break;

            case 'o':
            case 'O':
                strcpy(morse[i], "---");
                break;

            case 'p':
            case 'P':
                strcpy(morse[i], ".--.");
                break;

            case 'q':
            case 'Q':
                strcpy(morse[i], "--.-");
                break;

            case 'r':
            case 'R':
                strcpy(morse[i], ".-.");
                break;

            case 's':
            case 'S':
                strcpy(morse[i], "...");
                break;

            case 't':
            case 'T':
                strcpy(morse[i], "-");
                break;

            case 'u':
            case 'U':
                strcpy(morse[i], "..-");
                break;

            case 'v':
            case 'V':
                strcpy(morse[i], "...-");
                break;

            case 'w':
            case 'W':
                strcpy(morse[i], ".--");
                break;

            case 'x':
            case 'X':
                strcpy(morse[i], "-..-");
                break;

            case 'y':
            case 'Y':
                strcpy(morse[i], "-.--");
                break;

            case 'z':
            case 'Z':
                strcpy(morse[i], "--..");
                break;

            case ' ':
                strcpy(morse[i], "/");
                break;

            default:
                printf("\nSorry, the input contains an invalid character. Please try again.\n");
                return 0;
        }
    }

    printf("\n\nThe Morse code of your input is: ");
    for(i = 0; i < length; i++)
    {
        for(j = 0; j < strlen(morse[i]); j++)
        {
            if(morse[i][j] == '.')
            {
                dot();
            }
            else if(morse[i][j] == '-')
            {
                dash();
            }
        }

        printf(" ");
    }

    printf("\n\nThank you for using this cheerful C Text to Morse code conversion program!\n");

    return 0;
}

void dot()
{
    printf(".");
}

void dash()
{
    printf("-");
}