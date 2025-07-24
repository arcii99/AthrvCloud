//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Cyberpunk
#include <stdio.h>

int main() {
    char str[50];
    int i, j;

    printf("Enter a string to convert to ASCII art:\n");
    scanf("%s", str);

    printf("\n");

    // Top line
    for (i = 0; i < 7; i++) {
        for (j = 0; str[j] != '\0'; j++) {
            switch (str[j]) {
                case 'A':
                    printf(" _   _ \n");
                    break;
                case 'B':
                    printf("|_| |_|\n");
                    break;
                case 'C':
                    printf("|      \n");
                    break;
                case 'D':
                    printf("|\\_/|_ \n");
                    break;
                case 'E':
                    printf("|______|\n");
                    break;
                case 'F':
                    printf("|      \n");
                    break;
                case 'G':
                    printf("|  _  _ \n");
                    break;
                case 'H':
                    printf("|_| |_| \n");
                    break;
                case 'I':
                    printf("   |   \n");
                    break;
                case 'J':
                    printf("   |_| \n");
                    break;
                case 'K':
                    printf("|_/ \\_/\n");
                    break;
                case 'L':
                    printf("|      \n");
                    break;
                case 'M':
                    printf("|\\/|\\/|\n");
                    break;
                case 'N':
                    printf("|\\ | | \n");
                    break;
                case 'O':
                    printf("|_| |_| \n");
                    break;
                case 'P':
                    printf("|_/   | \n");
                    break;
                case 'Q':
                    printf("|_| \\|/ \n");
                    break;
                case 'R':
                    printf("|_/ \\_| \n");
                    break;
                case 'S':
                    printf(" \\____/ \n");
                    break;
                case 'T':
                    printf("   |   \n");
                    break;
                case 'U':
                    printf("|       |\n");
                    break;
                case 'V':
                    printf("\\_/   \\_/ \n");
                    break;
                case 'W':
                    printf("|\\ | /\\ |\n");
                    break;
                case 'X':
                    printf("\\_/   \\_/ \n");
                    break;
                case 'Y':
                    printf("\\_\\_/\\_/\n");
                    break;
                case 'Z':
                    printf("\\_____/ \n");
                    break;
                default:
                    printf("        \n");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}