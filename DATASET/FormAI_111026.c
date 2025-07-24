//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_char(char c) {
    // Map ASCII character to corresponding art
    switch (c) { 
        case ' ':
            printf("%s", "   ");
            break;
        case '!':
            printf("%s", " ! ");
            break;
        case '"':
            printf("%s", " \" ");
            break;
        case '#':
            printf("%s", " # ");
            break;
        case '$':
            printf("%s", " $ ");
            break;
        case '%':
            printf("%s", " % ");
            break;
        case '&':
            printf("%s", " & ");
            break;
        case '\'':
            printf("%s", " \' ");
            break;
        case '(':
            printf("%s", " ( ");
            break;
        case ')':
            printf("%s", " ) ");
            break;
        case '*':
            printf("%s", " * ");
            break;
        case '+':
            printf("%s", " + ");
            break;
        case ',':
            printf("%s", " , ");
            break;
        case '-':
            printf("%s", " - ");
            break;
        case '.':
            printf("%s", " . ");
            break;
        case '/':
            printf("%s", " / ");
            break;
        case '0':
            printf("%s", " 000 ");
            break;
        case '1':
            printf("%s", " 111 ");
            break;
        case '2':
            printf("%s", " 222 ");
            break;
        case '3':
            printf("%s", " 333 ");
            break;
        case '4':
            printf("%s", " 444 ");
            break;
        case '5':
            printf("%s", " 555 ");
            break;
        case '6':
            printf("%s", " 666 ");
            break;
        case '7':
            printf("%s", " 777 ");
            break;
        case '8':
            printf("%s", " 888 ");
            break;
        case '9':
            printf("%s", " 999 ");
            break;
        case ':':
            printf("%s", " : ");
            break;
        case ';':
            printf("%s", " ; ");
            break;
        case '<':
            printf("%s", " < ");
            break;
        case '=':
            printf("%s", " = ");
            break;
        case '>':
            printf("%s", " > ");
            break;
        case '?':
            printf("%s", " ? ");
            break;
        case '@':
            printf("%s", " @@ ");
            break;
        case 'A':
            printf("%s", " A ");
            break;
        case 'B':
            printf("%s", " B ");
            break;
        case 'C':
            printf("%s", " C ");
            break;
        case 'D':
            printf("%s", " D ");
            break;
        case 'E':
            printf("%s", " E ");
            break;
        case 'F':
            printf("%s", " F ");
            break;
        case 'G':
            printf("%s", " G ");
            break;
        case 'H':
            printf("%s", " H ");
            break;
        case 'I':
            printf("%s", " I ");
            break;
        case 'J':
            printf("%s", " J ");
            break;
        case 'K':
            printf("%s", " K ");
            break;
        case 'L':
            printf("%s", " L ");
            break;
        case 'M':
            printf("%s", " M ");
            break;
        case 'N':
            printf("%s", " N ");
            break;
        case 'O':
            printf("%s", " O ");
            break;
        case 'P':
            printf("%s", " P ");
            break;
        case 'Q':
            printf("%s", " Q ");
            break;
        case 'R':
            printf("%s", " R ");
            break;
        case 'S':
            printf("%s", " S ");
            break;
        case 'T':
            printf("%s", " T ");
            break;
        case 'U':
            printf("%s", " U ");
            break;
        case 'V':
            printf("%s", " V ");
            break;
        case 'W':
            printf("%s", " W ");
            break;
        case 'X':
            printf("%s", " X ");
            break;
        case 'Y':
            printf("%s", " Y ");
            break;
        case 'Z':
            printf("%s", " Z ");
            break;
        case '[':
            printf("%s", " [ ");
            break;
        case '\\':
            printf("%s", " \\ ");
            break;
        case ']':
            printf("%s", " ] ");
            break;
        case '^':
            printf("%s", " ^ ");
            break;
        case '_':
            printf("%s", " __ ");
            break;
        case '`':
            printf("%s", " ` ");
            break;
        case 'a':
            printf("%s", " a ");
            break;
        case 'b':
            printf("%s", " b ");
            break;
        case 'c':
            printf("%s", " c ");
            break;
        case 'd':
            printf("%s", " d ");
            break;
        case 'e':
            printf("%s", " e ");
            break;
        case 'f':
            printf("%s", " f ");
            break;
        case 'g':
            printf("%s", " g ");
            break;
        case 'h':
            printf("%s", " h ");
            break;
        case 'i':
            printf("%s", " i ");
            break;
        case 'j':
            printf("%s", " j ");
            break;
        case 'k':
            printf("%s", " k ");
            break;
        case 'l':
            printf("%s", " l ");
            break;
        case 'm':
            printf("%s", " m ");
            break;
        case 'n':
            printf("%s", " n ");
            break;
        case 'o':
            printf("%s", " o ");
            break;
        case 'p':
            printf("%s", " p ");
            break;
        case 'q':
            printf("%s", " q ");
            break;
        case 'r':
            printf("%s", " r ");
            break;
        case 's':
            printf("%s", " s ");
            break;
        case 't':
            printf("%s", " t ");
            break;
        case 'u':
            printf("%s", " u ");
            break;
        case 'v':
            printf("%s", " v ");
            break;
        case 'w':
            printf("%s", " w ");
            break;
        case 'x':
            printf("%s", " x ");
            break;
        case 'y':
            printf("%s", " y ");
            break;
        case 'z':
            printf("%s", " z ");
            break;
        case '{':
            printf("%s", " { ");
            break;
        case '|':
            printf("%s", " | ");
            break;
        case '}':
            printf("%s", " } ");
            break;
        case '~':
            printf("%s", " ~ ");
            break;
        default:
            printf("%s", "???");
            break;
    }
}

int main() {
    printf("Enter a message to convert to ASCII art:\n");
    char message[100];
    fgets(message, 100, stdin);
    
    // Loop through each line of ASCII art
    for (int i = 0; i < 8; i++) {
        // Loop through each character in original message
        for (int j = 0; j < strlen(message); j++) {
            print_char(message[j]);
        }
        printf("\n");
    }
    
    return 0;
}