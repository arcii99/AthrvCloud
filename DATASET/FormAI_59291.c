//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main()
{
    //Greet the user and ask for input
    printf("Hello there! Let's convert your text to Morse code!\n");
    printf("Enter your text: \n");
    char text[100];
    fgets(text, 100, stdin);

    //Convert text to Morse code
    char morse[100];
    int i, j;
    for(i=0; i<strlen(text); i++)
    {
        switch(text[i])
        {
            case 'a': strcpy(morse+i*5, ".- "); break;
            case 'b': strcpy(morse+i*5, "-... "); break;
            case 'c': strcpy(morse+i*5, "-.-. "); break;
            case 'd': strcpy(morse+i*5, "-.. "); break;
            case 'e': strcpy(morse+i*5, ". "); break;
            case 'f': strcpy(morse+i*5, "..-. "); break;
            case 'g': strcpy(morse+i*5, "--. "); break;
            case 'h': strcpy(morse+i*5, ".... "); break;
            case 'i': strcpy(morse+i*5, ".. "); break;
            case 'j': strcpy(morse+i*5, ".--- "); break;
            case 'k': strcpy(morse+i*5, "-.- "); break;
            case 'l': strcpy(morse+i*5, ".-.. "); break;
            case 'm': strcpy(morse+i*5, "-- "); break;
            case 'n': strcpy(morse+i*5, "-. "); break;
            case 'o': strcpy(morse+i*5, "--- "); break;
            case 'p': strcpy(morse+i*5, ".--. "); break;
            case 'q': strcpy(morse+i*5, "--.- "); break;
            case 'r': strcpy(morse+i*5, ".-. "); break;
            case 's': strcpy(morse+i*5, "... "); break;
            case 't': strcpy(morse+i*5, "- "); break;
            case 'u': strcpy(morse+i*5, "..- "); break;
            case 'v': strcpy(morse+i*5, "...- "); break;
            case 'w': strcpy(morse+i*5, ".-- "); break;
            case 'x': strcpy(morse+i*5, "-..- "); break;
            case 'y': strcpy(morse+i*5, "-.-- "); break;
            case 'z': strcpy(morse+i*5, "--.. "); break;
            case ' ': strcpy(morse+i*5, "   "); break;
            default: strcpy(morse+i*5, ""); break;
        }
    }

    //Print the Morse code result
    printf("Here's your text in Morse code:\n%s", morse);

    return 0;
}