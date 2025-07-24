//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMorseCode(char c, char *morseCode);
void convertToMorseCode(char *text, char *morseCode);
void printInShockedStyle(char *morseCode);

int main()
{
    char text[100], morseCode[500];
    printf("Enter text to be converted to Morse Code: ");
    fgets(text, 100, stdin);
    convertToMorseCode(text, morseCode);
    printf("\n\nMorse Code: \n\n");
    printInShockedStyle(morseCode);
    return 0;
}

void printMorseCode(char c, char *morseCode)
{
    strcat(morseCode, " ");
    if(c == 'a' || c == 'A')
        strcat(morseCode, ".-");
    else if(c == 'b' || c == 'B')
        strcat(morseCode, "-...");
    else if(c == 'c' || c == 'C')
        strcat(morseCode, "-.-.");
    else if(c == 'd' || c == 'D')
        strcat(morseCode, "-..");
    else if(c == 'e' || c == 'E')
        strcat(morseCode, ".");
    else if(c == 'f' || c == 'F')
        strcat(morseCode, "..-.");
    else if(c == 'g' || c == 'G')
        strcat(morseCode, "--.");
    else if(c == 'h' || c == 'H')
        strcat(morseCode, "....");
    else if(c == 'i' || c == 'I')
        strcat(morseCode, "..");
    else if(c == 'j' || c == 'J')
        strcat(morseCode, ".---");
    else if(c == 'k' || c == 'K')
        strcat(morseCode, "-.-");
    else if(c == 'l' || c == 'L')
        strcat(morseCode, ".-..");
    else if(c == 'm' || c == 'M')
        strcat(morseCode, "--");
    else if(c == 'n' || c == 'N')
        strcat(morseCode, "-.");
    else if(c == 'o' || c == 'O')
        strcat(morseCode, "---");
    else if(c == 'p' || c == 'P')
        strcat(morseCode, ".--.");
    else if(c == 'q' || c == 'Q')
        strcat(morseCode, "--.-");
    else if(c == 'r' || c == 'R')
        strcat(morseCode, ".-.");
    else if(c == 's' || c == 'S')
        strcat(morseCode, "...");
    else if(c == 't' || c == 'T')
        strcat(morseCode, "-");
    else if(c == 'u' || c == 'U')
        strcat(morseCode, "..-");
    else if(c == 'v' || c == 'V')
        strcat(morseCode, "...-");
    else if(c == 'w' || c == 'W')
        strcat(morseCode, ".--");
    else if(c == 'x' || c == 'X')
        strcat(morseCode, "-..-");
    else if(c == 'y' || c == 'Y')
        strcat(morseCode, "-.--");
    else if(c == 'z' || c == 'Z')
        strcat(morseCode, "--..");
    else if(c == '1')
        strcat(morseCode, ".----");
    else if(c == '2')
        strcat(morseCode, "..---");
    else if(c == '3')
        strcat(morseCode, "...--");
    else if(c == '4')
        strcat(morseCode, "....-");
    else if(c == '5')
        strcat(morseCode, ".....");
    else if(c == '6')
        strcat(morseCode, "-....");
    else if(c == '7')
        strcat(morseCode, "--...");
    else if(c == '8')
        strcat(morseCode, "---..");
    else if(c == '9')
        strcat(morseCode, "----.");
    else if(c == '0')
        strcat(morseCode, "-----");
    else if(c == ' ')
        strcat(morseCode, "/");
}

void convertToMorseCode(char *text, char *morseCode)
{
    int i, len = strlen(text);

    for(i = 0; i < len-1; i++)
    {
        if(text[i] == '\n')
            continue;
        printMorseCode(text[i], morseCode);
    }
}

void printInShockedStyle(char *morseCode)
{
    printf("\t\t***** MINTY FRESH MORSE CODE CONVERSION *****\n\n");
    int i, len = strlen(morseCode);
    for(i = 0; i < len; i++)
    {
        if(morseCode[i] == '/')
            printf("\n");
        else if(morseCode[i] == '-')
            printf("**** ");
        else if(morseCode[i] == '.')
            printf("*** ");
        else if(morseCode[i] == ' ')
            printf("** ");
    }
}