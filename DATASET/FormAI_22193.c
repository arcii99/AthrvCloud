//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: intelligent
#include <stdio.h>
#include <string.h>

/*
The following code is a C program that converts text to Morse code.
*/

void printMorseCode(char letter)
{
    switch (letter)
    {
    case 'a':
    case 'A':
        printf(".- ");
        break;
    case 'b':
    case 'B':
        printf("-... ");
        break;
    case 'c':
    case 'C':
        printf("-.-. ");
        break;
    case 'd':
    case 'D':
        printf("-.. ");
        break;
    case 'e':
    case 'E':
        printf(". ");
        break;
    case 'f':
    case 'F':
        printf("..-. ");
        break;
    case 'g':
    case 'G':
        printf("--. ");
        break;
    case 'h':
    case 'H':
        printf(".... ");
        break;
    case 'i':
    case 'I':
        printf(".. ");
        break;
    case 'j':
    case 'J':
        printf(".--- ");
        break;
    case 'k':
    case 'K':
        printf("-.- ");
        break;
    case 'l':
    case 'L':
        printf(".-.. ");
        break;
    case 'm':
    case 'M':
        printf("-- ");
        break;
    case 'n':
    case 'N':
        printf("-. ");
        break;
    case 'o':
    case 'O':
        printf("--- ");
        break;
    case 'p':
    case 'P':
        printf(".--. ");
        break;
    case 'q':
    case 'Q':
        printf("--.- ");
        break;
    case 'r':
    case 'R':
        printf(".-. ");
        break;
    case 's':
    case 'S':
        printf("... ");
        break;
    case 't':
    case 'T':
        printf("- ");
        break;
    case 'u':
    case 'U':
        printf("..- ");
        break;
    case 'v':
    case 'V':
        printf("...- ");
        break;
    case 'w':
    case 'W':
        printf(".-- ");
        break;
    case 'x':
    case 'X':
        printf("-..- ");
        break;
    case 'y':
    case 'Y':
        printf("-.-- ");
        break;
    case 'z':
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
    case '.':
        printf(".-.-.- ");
        break;
    case ',':
        printf("--..-- ");
        break;
    case '?':
        printf("..--.. ");
        break;
    case '\'':
        printf(".----. ");
        break;
    case '!':
        printf("-.-.-- ");
        break;
    case '/':
        printf("-..-. ");
        break;
    case '(':
        printf("-.--. ");
        break;
    case ')':
        printf("-.--.- ");
        break;
    case '&':
        printf(".-... ");
        break;
    case ':':
        printf("---... ");
        break;
    case ';':
        printf("-.-.-. ");
        break;
    case '=':
        printf("-...- ");
        break;
    case '+':
        printf(".-.-. ");
        break;
    case '-':
        printf("-....- ");
        break;
    case '_':
        printf("..--.- ");
        break;
    case '"':
        printf(".-..-. ");
        break;
    case '$':
        printf("...-..- ");
        break;
    case '@':
        printf(".--.-. ");
        break;
    default:
        printf(" ");
        break;
    }
}

int main()
{
    char text[100];
    printf("Enter text to be converted to Morse Code: ");
    fgets(text, 100, stdin);
    printf("Morse Code: ");
    for (int i = 0; i < strlen(text); i++)
    {
        printMorseCode(text[i]);
    }
    printf("\n");
    return 0;
}