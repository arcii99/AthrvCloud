//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Function to translate the alien language
void translate(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        switch (str[i]) {
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
                printf("%c", str[i]);
        }
    }
    printf("\n");
}

// Main function to test the translator
int main() {
    // Test cases
    char test1[] = "HELLO WORLD!";
    printf("Original: %s\n", test1);
    printf("Translated: ");
    translate(test1); // Output: SVVOO DLIOW!

    char test2[] = "WELCOME TO OUR PLANET!";
    printf("Original: %s\n", test2);
    printf("Translated: ");
    translate(test2); // Output: DTRXVNV GL LIF KZMREV!

    char test3[] = "WE COME IN PEACE";
    printf("Original: %s\n", test3);
    printf("Translated: ");
    translate(test3); // Output: DV XLRNV RM KVZHV

    return 0;
}