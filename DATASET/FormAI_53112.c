//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: satisfied
#include <stdio.h>
#include <string.h>

void translate(char* alien_lang) {
    int len = strlen(alien_lang);
    for (int i = 0; i < len; i++) {
        switch (alien_lang[i]) {
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
                printf("%c", alien_lang[i]);
                break;
        }
    }
}

int main() {
    char alien_lang[] = "YR HVVIVG GRNV";
    translate(alien_lang);
    printf("\n");
    return 0;
}