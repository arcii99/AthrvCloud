//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[50]; // maximum input of 50 characters
    char art[15][50]; // array to hold ASCII art

    // prompts user for input
    printf("Enter a word or phrase to generate ASCII art: ");
    scanf("%s", input);

    int length = strlen(input); // gets the length of user input
    int ascii[length]; // array to hold ASCII values of each character in input

    // loops through each character in input, gets ASCII value, and adds it to ascii array
    for (int i = 0; i < length; i++) {
        ascii[i] = (int)input[i];
    }

    // creates ASCII art using the ASCII values in the ascii array
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < length; j++) {
            switch(ascii[j]) {
                case 32: // space
                    strcat(art[i], "     ");
                    break;
                case 33: // !
                    strcat(art[i], " __  ");
                    break;
                case 34: // "
                    strcat(art[i], "|__| ");
                    break;
                case 35: // #
                    strcat(art[i], "|#|#|");
                    break;
                case 36: // $
                    strcat(art[i], "|$-->");
                    break;
                case 37: // %
                    strcat(art[i], "|%/\\ ");
                    break;
                case 38: // &
                    strcat(art[i], "|&/&\\");
                    break;
                case 39: // '
                    strcat(art[i], "   | ");
                    break;
                case 40: // (
                    strcat(art[i], " /   ");
                    break;
                case 41: // )
                    strcat(art[i], "\\     ");
                    break;
                case 42: // *
                    strcat(art[i], "*|_|*");
                    break;
                case 43: // +
                    strcat(art[i], "  +  ");
                    break;
                case 44: // ,
                    strcat(art[i], "  ,  ");
                    break;
                case 45: // -
                    strcat(art[i], "-----");
                    break;
                case 46: // .
                    strcat(art[i], "     ");
                    break;
                case 47: // /
                    strcat(art[i], " \\   ");
                    break;
                case 48: // 0
                    strcat(art[i], " ___ ");
                    break;
                case 49: // 1
                    strcat(art[i], "/ |  ");
                    break;
                case 50: // 2
                    strcat(art[i], "/__\\ ");
                    break;
                case 51: // 3
                    strcat(art[i], "\\___/");
                    break;
                case 52: // 4
                    strcat(art[i], "|_  |");
                    break;
                case 53: // 5
                    strcat(art[i], "|___\\");
                    break;
                case 54: // 6
                    strcat(art[i], "/ ___|");
                    break;
                case 55: // 7
                    strcat(art[i], "\\    ");
                    break;
                case 56: // 8
                    strcat(art[i], "|\\__/|");
                    break;
                case 57: // 9
                    strcat(art[i], "| ___|");
                    break;
                case 58: // :
                    strcat(art[i], "     ");
                    break;
                case 59: // ;
                    strcat(art[i], "  ,  ");
                    break;
                case 60: // <
                    strcat(art[i], "  /\\ ");
                    break;
                case 61: // =
                    strcat(art[i], "=====");
                    break;
                case 62: // >
                    strcat(art[i], "     \\/");
                    break;
                case 63: // ?
                    strcat(art[i], "/__/ ");
                    break;
                case 64: // @
                    strcat(art[i], "  __ ");
                    break;
                case 65: // A
                    strcat(art[i], "/_\\  ");
                    break;
                case 66: // B
                    strcat(art[i], "|__/ ");
                    break;
                case 67: // C
                    strcat(art[i], "\\___/");
                    break;
                case 68: // D
                    strcat(art[i], "|__/ ");
                    break;
                case 69: // E
                    strcat(art[i], "|___ ");
                    break;
                case 70: // F
                    strcat(art[i], "|___ ");
                    break;
                case 71: // G
                    strcat(art[i], "\\___|");
                    break;
                case 72: // H
                    strcat(art[i], "|__| ");
                    break;
                case 73: // I
                    strcat(art[i], "  |  ");
                    break;
                case 74: // J
                    strcat(art[i], "   | ");
                    break;
                case 75: // K
                    strcat(art[i], "|/ \\ ");
                    break;
                case 76: // L
                    strcat(art[i], "|    ");
                    break;
                case 77: // M
                    strcat(art[i], "|\\/| ");
                    break;
                case 78: // N
                    strcat(art[i], "|\\ | ");
                    break;
                case 79: // O
                    strcat(art[i], "\\___/");
                    break;
                case 80: // P
                    strcat(art[i], "|__/ ");
                    break;
                case 81: // Q
                    strcat(art[i], "\\_\\_|");
                    break;
                case 82: // R
                    strcat(art[i], "|__/ ");
                    break;
                case 83: // S
                    strcat(art[i], "\\\\__/");
                    break;
                case 84: // T
                    strcat(art[i], "  |  ");
                    break;
                case 85: // U
                    strcat(art[i], "|   |");
                    break;
                case 86: // V
                    strcat(art[i], "\\/\\/");
                    break;
                case 87: // W
                    strcat(art[i], "|/\\|)");
                    break;
                case 88: // X
                    strcat(art[i], "/\\ / ");
                    break;
                case 89: // Y
                    strcat(art[i], "\\_/   ");
                    break;
                case 90: // Z
                    strcat(art[i], "\\__/ ");
                    break;
                case 91: // [
                    strcat(art[i], "  /   ");
                    break;
                case 92: // '\'
                    strcat(art[i], "/    ");
                    break;
                case 93: // ]
                    strcat(art[i], "\\   ");
                    break;
                case 94: // ^
                    strcat(art[i], " /\\  ");
                    break;
                case 95: // _
                    strcat(art[i], "_____");
                    break;
                case 96: // `
                    strcat(art[i], "   | ");
                    break;
                case 97: // a
                    strcat(art[i], "\\_/");
                    break;
                case 98: // b
                    strcat(art[i], "|__/ ");
                    break;
                case 99: // c
                    strcat(art[i], "\\___/");
                    break;
                case 100: // d
                    strcat(art[i], "\\__|/");
                    break;
                case 101: // e
                    strcat(art[i], "|___ ");
                    break;
                case 102: // f
                    strcat(art[i], "|___ ");
                    break;
                case 103: // g
                    strcat(art[i], "\\_\\_|");
                    break;
                case 104: // h
                    strcat(art[i], "|__| ");
                    break;
                case 105: // i
                    strcat(art[i], "  |  ");
                    break;
                case 106: // j
                    strcat(art[i], "   | ");
                    break;
                case 107: // k
                    strcat(art[i], "|/ \\ ");
                    break;
                case 108: // l
                    strcat(art[i], "|    ");
                    break;
                case 109: // m
                    strcat(art[i], "|\\/| ");
                    break;
                case 110: // n
                    strcat(art[i], "|\\ | ");
                    break;
                case 111: // o
                    strcat(art[i], "\\___/");
                    break;
                case 112: // p
                    strcat(art[i], "|__/ ");
                    break;
                case 113: // q
                    strcat(art[i], "\\_\\_|");
                    break;
                case 114: // r
                    strcat(art[i], "|___ ");
                    break;
                case 115: // s
                    strcat(art[i], "\\\\__/");
                    break;
                case 116: // t
                    strcat(art[i], "  |  ");
                    break;
                case 117: // u
                    strcat(art[i], "|   |");
                    break;
                case 118: // v
                    strcat(art[i], "\\/\\/");
                    break;
                case 119: // w
                    strcat(art[i], "|/\\|)");
                    break;
                case 120: // x
                    strcat(art[i], "/\\ / ");
                    break;
                case 121: // y
                    strcat(art[i], "\\_/   ");
                    break;
                case 122: // z
                    strcat(art[i], "\\__/ ");
                    break;
                case 123: // {
                    strcat(art[i], "  /\\ ");
                    break;
                case 124: // |
                    strcat(art[i], "  |  ");
                    break;
                case 125: // }
                    strcat(art[i], "/\\  ");
                    break;
                case 126: // ~
                    strcat(art[i], "/\\/\\");
                    break;
                default: // if character is not recognized, prints a space
                    strcat(art[i], "     ");
                    break;
            }
        }
    }

    // prints ASCII art
    for (int i = 0; i < 15; i++) {
        printf("%s\n", art[i]);
    }

    return 0;
}