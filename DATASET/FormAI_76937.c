//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: introspective
#include <stdio.h>
#include <string.h>

// function to convert character to morse code
char* char_to_morse(char c)
{
    switch(c)
    {
        case 'a':
        case 'A':
            return ".-";
        case 'b':
        case 'B':
            return "-...";
        case 'c':
        case 'C':
            return "-.-.";
        case 'd':
        case 'D':
            return "-..";
        case 'e':
        case 'E':
            return ".";
        case 'f':
        case 'F':
            return "..-.";
        case 'g':
        case 'G':
            return "--.";
        case 'h':
        case 'H':
            return "....";
        case 'i':
        case 'I':
            return "..";
        case 'j':
        case 'J':
            return ".---";
        case 'k':
        case 'K':
            return "-.-";
        case 'l':
        case 'L':
            return ".-..";
        case 'm':
        case 'M':
            return "--";
        case 'n':
        case 'N':
            return "-.";
        case 'o':
        case 'O':
            return "---";
        case 'p':
        case 'P':
            return ".--.";
        case 'q':
        case 'Q':
            return "--.-";
        case 'r':
        case 'R':
            return ".-.";
        case 's':
        case 'S':
            return "...";
        case 't':
        case 'T':
            return "-";
        case 'u':
        case 'U':
            return "..-";
        case 'v':
        case 'V':
            return "...-";
        case 'w':
        case 'W':
            return ".--";
        case 'x':
        case 'X':
            return "-..-";
        case 'y':
        case 'Y':
            return "-.--";
        case 'z':
        case 'Z':
            return "--..";
        case '0':
            return "-----";
        case '1':
            return ".----";
        case '2':
            return "..---";
        case '3':
            return "...--";
        case '4':
            return "....-";
        case '5':
            return ".....";
        case '6':
            return "-....";
        case '7':
            return "--...";
        case '8':
            return "---..";
        case '9':
            return "----.";
        default:
            return "";
    }
}

// function to convert text to morse code
char* text_to_morse(char* text)
{
    int i, j;
    char* morse = "";

    for(i=0; i<strlen(text); i++)
    {
        char* code = char_to_morse(text[i]);

        for(j=0; j<strlen(code); j++)
        {
            morse[strlen(morse)] = code[j];
        }

        if(i != strlen(text)-1)
        {
            morse[strlen(morse)] = ' ';
        }
    }

    return morse;
}

int main()
{
    char text[50];

    printf("Enter text to convert to morse code: ");
    fgets(text, 50, stdin);

    char* morse = text_to_morse(text);
    printf("Morse code: %s", morse);

    return 0;
}