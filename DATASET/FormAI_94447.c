//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToMorse(char c) //Function to convert a single character to morse code
{
    switch(c)
    {
        case 'a': printf(".- ");
                  break;
        case 'b': printf("-... ");
                  break;
        case 'c': printf("-.-. ");
                  break;
        case 'd': printf("-.. ");
                  break;
        case 'e': printf(". ");
                  break;
        case 'f': printf("..-. ");
                  break;
        case 'g': printf("--. ");
                  break;
        case 'h': printf(".... ");
                  break;
        case 'i': printf(".. ");
                  break;
        case 'j': printf(".--- ");
                  break;
        case 'k': printf("-.- ");
                  break;
        case 'l': printf(".-.. ");
                  break;
        case 'm': printf("-- ");
                  break;
        case 'n': printf("-. ");
                  break;
        case 'o': printf("--- ");
                  break;
        case 'p': printf(".--. ");
                  break;
        case 'q': printf("--.- ");
                  break;
        case 'r': printf(".-. ");
                  break;
        case 's': printf("... ");
                  break;
        case 't': printf("- ");
                  break;
        case 'u': printf("..- ");
                  break;
        case 'v': printf("...- ");
                  break;
        case 'w': printf(".-- ");
                  break;
        case 'x': printf("-..- ");
                  break;
        case 'y': printf("-.-- ");
                  break;
        case 'z': printf("--.. ");
                  break;
        case ' ': printf("  ");
                  break;
        default: printf("Invalid character\n");
                 break;
    }
}

void convertTextToMorse(char *text) //Function to convert the entire text to morse code
{
    int len = strlen(text);
    for(int i=0;i<len;i++)
    {
        convertToMorse(text[i]);
    }
}

int main()
{
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);
    convertTextToMorse(text);
    printf("\n");
    return 0;
}