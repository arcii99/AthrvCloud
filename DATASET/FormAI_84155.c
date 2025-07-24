//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>

int main() {
    printf("Welcome to Alien Language Translator!\n\n");

    char alien_language[100];
    printf("Enter an alien language message: ");
    scanf("%s", alien_language);

    printf("\nYour translated message is: ");

    for(int i = 0; alien_language[i] != '\0'; ++i) {
        switch(alien_language[i]) {
            case 'A':
                printf("Z");
                break;
            case 'B':
                printf("Y");
                break;
            case 'C':
                printf("X");
                break;
            case 'D':
                printf("W");
                break;
            case 'E':
                printf("V");
                break;
            case 'F':
                printf("U");
                break;
            case 'G':
                printf("T");
                break;
            case 'H':
                printf("S");
                break;
            case 'I':
                printf("R");
                break;
            case 'J':
                printf("Q");
                break;
            case 'K':
                printf("P");
                break;
            case 'L':
                printf("O");
                break;
            case 'M':
                printf("N");
                break;
            case 'N':
                printf("M");
                break;
            case 'O':
                printf("L");
                break;
            case 'P':
                printf("K");
                break;
            case 'Q':
                printf("J");
                break;
            case 'R':
                printf("I");
                break;
            case 'S':
                printf("H");
                break;
            case 'T':
                printf("G");
                break;
            case 'U':
                printf("F");
                break;
            case 'V':
                printf("E");
                break;
            case 'W':
                printf("D");
                break;
            case 'X':
                printf("C");
                break;
            case 'Y':
                printf("B");
                break;
            case 'Z':
                printf("A");
                break;
            default:
                printf("%c", alien_language[i]);
        }
    }
    
    printf("\n");

    return 0;
}