//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    char morse_code[1000] = "";
    int i, j;

    printf("Welcome to the Text to Morse code converter!\n");
    printf("Please enter the text that you want to convert.\n");

    fflush(stdin);
    fgets(text, sizeof(text), stdin);        

    printf("\nThank you for the input! Converting...\n");

    // Convert text to morse code
    for(i = 0; i < strlen(text); i++) {
        switch(text[i]) {
            case 'a':
            case 'A':
                strcat(morse_code, ".- ");
                break;
            case 'b':
            case 'B':
                strcat(morse_code, "-... ");
                break;
            case 'c':
            case 'C':
                strcat(morse_code, "-.-. ");
                break;
            case 'd':
            case 'D':
                strcat(morse_code, "-.. ");
                break;
            case 'e':
            case 'E':
                strcat(morse_code, ". ");
                break;
            case 'f':
            case 'F':
                strcat(morse_code, "..-. ");
                break;
            case 'g':
            case 'G':
                strcat(morse_code, "--. ");
                break;
            case 'h':
            case 'H':
                strcat(morse_code, ".... ");
                break;
            case 'i':
            case 'I':
                strcat(morse_code, ".. ");
                break;
            case 'j':
            case 'J':
                strcat(morse_code, ".--- ");
                break;
            case 'k':
            case 'K':
                strcat(morse_code, "-.- ");
                break;
            case 'l':
            case 'L':
                strcat(morse_code, ".-.. ");
                break;
            case 'm':
            case 'M':
                strcat(morse_code, "-- ");
                break;
            case 'n':
            case 'N':
                strcat(morse_code, "-. ");
                break;
            case 'o':
            case 'O':
                strcat(morse_code, "--- ");
                break;
            case 'p':
            case 'P':
                strcat(morse_code, ".--. ");
                break;
            case 'q':
            case 'Q':
                strcat(morse_code, "--.- ");
                break;
            case 'r':
            case 'R':
                strcat(morse_code, ".-. ");
                break;
            case 's':
            case 'S':
                strcat(morse_code, "... ");
                break;
            case 't':
            case 'T':
                strcat(morse_code, "- ");
                break;
            case 'u':
            case 'U':
                strcat(morse_code, "..- ");
                break;
            case 'v':
            case 'V':
                strcat(morse_code, "...- ");
                break;
            case 'w':
            case 'W':
                strcat(morse_code, ".-- ");
                break;
            case 'x':
            case 'X':
                strcat(morse_code, "-..- ");
                break;
            case 'y':
            case 'Y':
                strcat(morse_code, "-.-- ");
                break;
            case 'z':
            case 'Z':
                strcat(morse_code, "--.. ");
                break;
            case '0':
                strcat(morse_code, "----- ");
                break;
            case '1':
                strcat(morse_code, ".---- ");
                break;
            case '2':
                strcat(morse_code, "..--- ");
                break;
            case '3':
                strcat(morse_code, "...-- ");
                break;
            case '4':
                strcat(morse_code, "....- ");
                break;
            case '5':
                strcat(morse_code, "..... ");
                break;
            case '6':
                strcat(morse_code, "-.... ");
                break;
            case '7':
                strcat(morse_code, "--... ");
                break;
            case '8':
                strcat(morse_code, "---.. ");
                break;
            case '9':
                strcat(morse_code, "----. ");
                break;
            case ' ':
                strcat(morse_code, "/ ");
                break;
            default:
                break;
        }
    }

    printf("The Morse code for the text:\n");
    printf("%s", text);
    printf("is:\n");
    printf("%s\n", morse_code);

    printf("\nThank you for using the Text to Morse code converter!\n");
    printf("Have a nice day!\n");

    return 0;
}