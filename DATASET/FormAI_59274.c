//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* convert(char); // function to convert a single character to morse code

int main()
{
    char msg[100]; // message to convert
    char output[1000] = ""; // string to store converted morse code
    int i, j;

    printf("Enter a message to convert to morse code: ");
    scanf("%[^\n]", msg); // read input until newline character is encountered

    for(i=0; i<strlen(msg); i++)
    {
        if(isalpha(msg[i])) // check if character is alphabet
        {
            strcat(output, convert(toupper(msg[i]))); // convert uppercase alphabet to morse code and append to output
            strcat(output, " "); // add space between letters
        }
        else if(isdigit(msg[i])) // check if character is digit
        {
            strcat(output, convert(msg[i])); // convert digit to morse code and append to output
            strcat(output, " "); // add space between digits
        }
        else // character is invalid
        {
            printf("Invalid input!\n");
            return 1;
        }
    }

    printf("Morse Code: %s\n", output);

    return 0;
}

char* convert(char c)
{
    switch(c)
    {
        case 'A':
            return ".-";
        case 'B':
            return "-...";
        case 'C':
            return "-.-.";
        case 'D':
            return "-..";
        case 'E':
            return ".";
        case 'F':
            return "..-.";
        case 'G':
            return "--.";
        case 'H':
            return "....";
        case 'I':
            return "..";
        case 'J':
            return ".---";
        case 'K':
            return "-.-";
        case 'L':
            return ".-..";
        case 'M':
            return "--";
        case 'N':
            return "-.";
        case 'O':
            return "---";
        case 'P':
            return ".--.";
        case 'Q':
            return "--.-";
        case 'R':
            return ".-.";
        case 'S':
            return "...";
        case 'T':
            return "-";
        case 'U':
            return "..-";
        case 'V':
            return "...-";
        case 'W':
            return ".--";
        case 'X':
            return "-..-";
        case 'Y':
            return "-.--";
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