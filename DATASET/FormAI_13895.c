//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: visionary
#include<stdio.h>
#include<string.h>

void delay() {
    for(int i=0; i<10000000; i++);
}

void dot() {
    printf(". ");
    //Morse code for dot
    delay();
}

void dash() {
    printf("- ");
    //Morse code for dash
    delay();
}

void encode(char message[]) {
    for(int i=0; i<strlen(message); i++) {
        char ch = message[i];
        switch(ch) {
            case 'a':
            case 'A':
                dot(); dash();
                break;
            case 'b':
            case 'B':
                dash(); dot(); dot(); dot();
                break;
            case 'c':
            case 'C':
                dash(); dot(); dash(); dot();
                break;
            case 'd':
            case 'D':
                dash(); dot(); dot();
                break;
            case 'e':
            case 'E':
                dot();
                break;
            case 'f':
            case 'F':
                dot(); dot(); dash(); dot();
                break;
            case 'g':
            case 'G':
                dash(); dash(); dot();
                break;
            case 'h':
            case 'H':
                dot(); dot(); dot(); dot();
                break;
            case 'i':
            case 'I':
                dot(); dot();
                break;
            case 'j':
            case 'J':
                dot(); dash(); dash(); dash();
                break;
            case 'k':
            case 'K':
                dash(); dot(); dash();
                break;
            case 'l':
            case 'L':
                dot(); dash(); dot(); dot();
                break;
            case 'm':
            case 'M':
                dash(); dash();
                break;
            case 'n':
            case 'N':
                dash(); dot();
                break;
            case 'o':
            case 'O':
                dash(); dash(); dash();
                break;
            case 'p':
            case 'P':
                dot(); dash(); dash(); dot();
                break;
            case 'q':
            case 'Q':
                dash(); dash(); dot(); dash();
                break;
            case 'r':
            case 'R':
                dot(); dash(); dot();
                break;
            case 's':
            case 'S':
                dot(); dot(); dot();
                break;
            case 't':
            case 'T':
                dash();
                break;
            case 'u':
            case 'U':
                dot(); dot(); dash();
                break;
            case 'v':
            case 'V':
                dot(); dot(); dot(); dash();
                break;
            case 'w':
            case 'W':
                dot(); dash(); dash();
                break;
            case 'x':
            case 'X':
                dash(); dot(); dot(); dash();
                break;
            case 'y':
            case 'Y':
                dash(); dot(); dash(); dash();
                break;
            case 'z':
            case 'Z':
                dash(); dash(); dot(); dot();
                break;
            case ' ':
                delay(); delay(); delay();
                break;
            default:
                printf("Invalid character found.\n");
                break;
        }
    }
    printf("\n");
}

int main() {
    char message[100];

    printf("Enter the text message to encode into Morse code:\n");
    fgets(message, 100, stdin);

    printf("The Morse code representation of the message is:\n");
    encode(message);

    return 0;
}