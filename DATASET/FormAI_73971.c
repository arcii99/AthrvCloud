//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <string.h>

void textToMorse(char *text, int length);

char* morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", ".--.-.", ".-.-.-", "..--.-"};

char* alphaNumeric[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", " ", "_", ".", ","};

int main()
{
    char text[1000];
    printf("Enter a string: ");
    gets(text);
    int length = strlen(text);
    textToMorse(text, length);
    return 0;
}

void textToMorse(char *text, int length)
{
    if(length == 0) // base case
    {
        return;
    }
    else
    {
        char c = tolower(*text); // convert the character to lower case
        int index = -1;
        for(int i=0; i<sizeof(alphaNumeric); i++) // find the index of the character in alphaNumeric array
        {
            if(!strcmp(alphaNumeric[i], &c))
            {
                index = i;
                break;
            }
        }
        if(index != -1) // if character exists in alphaNumeric array
        {
            printf("%s ", morseCode[index]); // print the corresponding morse code
        }
        else // if character does not exist in alphaNumeric array
        {
            printf("? "); // print a question mark
        }
        textToMorse(text+1, length-1); // call the function recursively with the next character
    }
}