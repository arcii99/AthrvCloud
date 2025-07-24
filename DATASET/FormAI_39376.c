//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char *morse_code(char input);

int main()
{
    char text[MAX_LENGTH], morse[MAX_LENGTH * 6];
    int i, j;

    printf("Enter text to be converted to morse code: ");
    fgets(text, MAX_LENGTH, stdin);

    for (i = 0, j = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            // Add a dot to indicate word boundary
            strcat(morse, ". ");
            j += 2;
        }
        else
        {
            // Convert character to morse code and add to string
            char *code = morse_code(text[i]);
            strcpy(morse + j, code);
            j += strlen(code);
            strcat(morse, " ");
            j++;
        }
    }

    printf("Morse code: %s\n", morse);

    return 0;
}

char *morse_code(char input)
{
    switch (toupper(input))
    {
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        default: return "";
    }
}