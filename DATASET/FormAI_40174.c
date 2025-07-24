//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: minimalist
#include<stdio.h>
#include<string.h>

void convertToMorse(char message[]);
char* translate(char letter);

int main()
{
    char message[200];

    printf("Enter message to be converted to Morse code: ");
    fgets(message, 200, stdin);
    message[strcspn(message, "\n")] = 0; // remove trailing newline character

    convertToMorse(message);

    return 0;
}

void convertToMorse(char message[])
{
    int length = strlen(message);

    for(int i=0; i<length; i++)
    {
        char currChar = message[i];

        if(currChar >= 'a' && currChar <= 'z') // convert lowercase alphabets
        {
            printf("%s ", translate(currChar-32));
        }
        else if(currChar >= 'A' && currChar <= 'Z') // convert uppercase alphabets
        {
            printf("%s ", translate(currChar));
        }
        else if(currChar >= '0' && currChar <= '9') // convert numbers
        {
            printf("%s ", translate(currChar));
        }
        else if(currChar == ' ') // print space for whitespace
        {
            printf(" ");
        }
    }
}

char* translate(char letter)
{
    switch(letter)
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