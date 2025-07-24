//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];//text to be converted
    char morse[1000];//converted text stored here
    int morseIndex = 0;//index counter for morse

    printf("Hello! Welcome to the Text to Morse code converter.\n");
    printf("Please enter the text you want to convert:\n");
    fgets(text, 100, stdin);//getting input

    printf("\nGreat! Let me convert that to Morse code for you. Here it is:\n\n");

    for(int i=0; i<strlen(text); i++){
        switch(text[i]){
            case 'a':
            case 'A':
                strcat(morse, ".-");
                break;
            case 'b':
            case 'B':
                strcat(morse, "-...");
                break;
            case 'c':
            case 'C':
                strcat(morse, "-.-.");
                break;
            case 'd':
            case 'D':
                strcat(morse, "-..");
                break;
            case 'e':
            case 'E':
                strcat(morse, ".");
                break;
            case 'f':
            case 'F':
                strcat(morse, "..-.");
                break;
            case 'g':
            case 'G':
                strcat(morse, "--.");
                break;
            case 'h':
            case 'H':
                strcat(morse, "....");
                break;
            case 'i':
            case 'I':
                strcat(morse, "..");
                break;
            case 'j':
            case 'J':
                strcat(morse, ".---");
                break;
            case 'k':
            case 'K':
                strcat(morse, "-.-");
                break;
            case 'l':
            case 'L':
                strcat(morse, ".-..");
                break;
            case 'm':
            case 'M':
                strcat(morse, "--");
                break;
            case 'n':
            case 'N':
                strcat(morse, "-.");
                break;
            case 'o':
            case 'O':
                strcat(morse, "---");
                break;
            case 'p':
            case 'P':
                strcat(morse, ".--.");
                break;
            case 'q':
            case 'Q':
                strcat(morse, "--.-");
                break;
            case 'r':
            case 'R':
                strcat(morse, ".-.");
                break;
            case 's':
            case 'S':
                strcat(morse, "...");
                break;
            case 't':
            case 'T':
                strcat(morse, "-");
                break;
            case 'u':
            case 'U':
                strcat(morse, "..-");
                break;
            case 'v':
            case 'V':
                strcat(morse, "...-");
                break;
            case 'w':
            case 'W':
                strcat(morse, ".--");
                break;
            case 'x':
            case 'X':
                strcat(morse, "-..-");
                break;
            case 'y':
            case 'Y':
                strcat(morse, "-.--");
                break;
            case 'z':
            case 'Z':
                strcat(morse, "--..");
                break;
            case ' ':
                strcat(morse, " ");
                break;
            default:
                break;
        }
        strcat(morse, "  ");//adding two spaces after each character to indicate end of character
    }

    printf("%s\n", morse);//printing the converted string
    printf("\nEnjoy using the Morse code. Have a nice day!");
    return 0;
}