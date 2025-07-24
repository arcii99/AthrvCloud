//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: careful
#include <stdio.h>
#include <string.h>

// define morse code of each character
char *morseCode[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

// function to convert a single character to morse code
void charToMorse(char c)
{
    if (c >= 'a' && c <= 'z')
        printf("%s ", morseCode[c - 'a']);
    else if (c >= 'A' && c <= 'Z')
        printf("%s ", morseCode[c - 'A']);
    else if (c >= '0' && c <= '9')
        printf("%s ", morseCode[c - '0' + 26]);
    else if (c == ' ')
        printf(" ");
}

// function to convert a string to morse code
void stringToMorse(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        charToMorse(str[i]);
    }
}

int main()
{
    char str[100];

    printf("Enter a string to convert to Morse code: ");
    fgets(str, 100, stdin);

    printf("Morse code: ");
    stringToMorse(str);

    return 0;
}