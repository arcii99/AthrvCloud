//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *textToMorse(char c);

int main(void)
{
    char text[100], morse[500], *m;
    int i, j;
    printf("Enter text to be converted to Morse code: ");
    fgets(text, 100, stdin);

    //convert to uppercase
    for(i = 0; text[i]; i++){
        text[i] = toupper(text[i]);
    }

    //convert to morse code
    for(i = 0; text[i]; i++){
        if(text[i] == ' ' || text[i] == '\n'){
            strcat(morse, "   "); //3 spaces for word boundary
        } else {
            m = textToMorse(text[i]);
            strcat(morse, m);
            strcat(morse, " "); //1 space for letter boundary
        }
    }

    //print morse code
    printf("Morse code: %s\n", morse);

    return 0;
}

char *textToMorse(char c)
{
    static char morse[10];
    switch(c){
        case 'A':
            strcpy(morse, ".-");
            break;
        case 'B':
            strcpy(morse, "-...");
            break;
        case 'C':
            strcpy(morse, "-.-.");
            break;
        case 'D':
            strcpy(morse, "-..");
            break;
        case 'E':
            strcpy(morse, ".");
            break;
        case 'F':
            strcpy(morse, "..-.");
            break;
        case 'G':
            strcpy(morse, "--.");
            break;
        case 'H':
            strcpy(morse, "....");
            break;
        case 'I':
            strcpy(morse, "..");
            break;
        case 'J':
            strcpy(morse, ".---");
            break;
        case 'K':
            strcpy(morse, "-.-");
            break;
        case 'L':
            strcpy(morse, ".-..");
            break;
        case 'M':
            strcpy(morse, "--");
            break;
        case 'N':
            strcpy(morse, "-.");
            break;
        case 'O':
            strcpy(morse, "---");
            break;
        case 'P':
            strcpy(morse, ".--.");
            break;
        case 'Q':
            strcpy(morse, "--.-");
            break;
        case 'R':
            strcpy(morse, ".-.");
            break;
        case 'S':
            strcpy(morse, "...");
            break;
        case 'T':
            strcpy(morse, "-");
            break;
        case 'U':
            strcpy(morse, "..-");
            break;
        case 'V':
            strcpy(morse, "...-");
            break;
        case 'W':
            strcpy(morse, ".--");
            break;
        case 'X':
            strcpy(morse, "-..-");
            break;
        case 'Y':
            strcpy(morse, "-.--");
            break;
        case 'Z':
            strcpy(morse, "--..");
            break;
        case '1':
            strcpy(morse, ".----");
            break;
        case '2':
            strcpy(morse, "..---");
            break;
        case '3':
            strcpy(morse, "...--");
            break;
        case '4':
            strcpy(morse, "....-");
            break;
        case '5':
            strcpy(morse, ".....");
            break;
        case '6':
            strcpy(morse, "-....");
            break;
        case '7':
            strcpy(morse, "--...");
            break;
        case '8':
            strcpy(morse, "---..");
            break;
        case '9':
            strcpy(morse, "----.");
            break;
        case '0':
            strcpy(morse, "-----");
            break;
        default:
            strcpy(morse, "");
            break;
    }
    return morse;
}