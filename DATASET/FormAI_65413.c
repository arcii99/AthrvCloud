//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

char* morseCodeConversion(char);

int main() {

    char text[100];
    printf("Enter the text you want to convert to Morse code:\n");
    fgets(text, 100, stdin);

    printf("The Morse code for entered text is: \n");

    for(int i=0;i<strlen(text);i++){
      
        if(text[i] == ' '){
            printf(" ");
            continue;
        }
        char* morse = morseCodeConversion(text[i]);
        printf("%s", morse);
        free(morse);
    }

    printf("\nCode by Sherlock Holmes");
    return 0;
}

char* morseCodeConversion(char letter){

    char* code;
    switch(letter){
        case 'a':
        case 'A':
            code = ".- ";
            break;
        case 'b':
        case 'B':
            code = "-... ";
            break;
        case 'c':
        case 'C':
            code = "-.-. ";
            break;
        case 'd':
        case 'D':
            code = "-.. ";
            break;
        case 'e':
        case 'E':
            code = ". ";
            break;
        case 'f':
        case 'F':
            code = "..-. ";
            break;
        case 'g':
        case 'G':
            code = "--. ";
            break;
        case 'h':
        case 'H':
            code = ".... ";
            break;
        case 'i':
        case 'I':
            code = ".. ";
            break;
        case 'j':
        case 'J':
            code = ".--- ";
            break;
        case 'k':
        case 'K':
            code = "-.- ";
            break;
        case 'l':
        case 'L':
            code = ".-.. ";
            break;
        case 'm':
        case 'M':
            code = "-- ";
            break;
        case 'n':
        case 'N':
            code = "-. ";
            break;
         case 'o':
        case 'O':
            code = "--- ";
            break;
        case 'p':
        case 'P':
            code = ".--. ";
            break;
        case 'q':
        case 'Q':
            code = "--.- ";
            break;
        case 'r':
        case 'R':
            code = ".-. ";
            break;
        case 's':
        case 'S':
            code = "... ";
            break;
        case 't':
        case 'T':
            code = "- ";
            break;
        case 'u':
        case 'U':
            code = "..- ";
            break;
        case 'v':
        case 'V':
            code = "...- ";
            break;
        case 'w':
        case 'W':
            code = ".-- ";
            break;
        case 'x':
        case 'X':
            code = "-..- ";
            break;
        case 'y':
        case 'Y':
            code = "-.-- ";
            break;
        case 'z':
        case 'Z':
            code = "--.. ";
            break;
        default:
            code = "";
            break;
    }

    return code;
}