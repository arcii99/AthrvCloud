//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>

// Function to convert text to ASCII art
void text_art(char* text) {
    int i, j;
    for(i = 0; text[i] != '\0'; i++) {
        for(j = 0; j < 7; j++) {
            switch(text[i]) {
                case 'A':
                    printf("%c", j == 3 ? '*' : ' ');
                    break;
                case 'B':
                    printf("%c", j == 0 || j == 6 || j == 3 || j == 4 || j == 5 ? '*' : ' ');
                    break;
                case 'C':
                    printf("%c", j == 0 || j == 6 || j == 1 || j == 5 ? '*' : ' ');
                    break;
                case 'D':
                    printf("%c", j == 0 || j == 6 || j == 1 || j == 2 || j == 5 ? '*' : ' ');
                    break;
                case 'E':
                    printf("%c", j == 0 || j == 6 || j == 3 || j == 4 || j == 5 ? '*' : ' ');
                    break;
                case 'F':
                    printf("%c", j == 0 || j == 3 || j == 4 || j == 5 ? '*' : ' ');
                    break;
                case 'G':
                    printf("%c", j == 0 || j == 6 || j == 1 || j == 3 || j == 4 || j == 5 ? '*' : ' ');
                    break;
                case 'H':
                    printf("%c", j == 0 || j == 6 || j == 3 ? '*' : ' ');
                    break;     
                case 'I':
                    printf("%c", j == 0 || j == 6 || j == 1 || j == 2 || j == 3 || j == 4 || j == 5 ? '*' : ' ');
                    break;
                case 'J':
                    printf("%c", j == 1 || j == 6 || j == 5 || j == 4 ? '*' : ' ');
                    break;
                case 'K':
                    printf("%c", j == 0 || j == 6 || j == 3 || (j == 2 && i <= 3) || (j == 1 && i >= 3) || (j == 4 && i >= 3) || (j == 5 && i <= 3) ? '*' : ' ');
                    break;
                case 'L':
                    printf("%c", j == 0 || j == 6 || j == 5 ? '*' : ' ');
                    break;
                case 'M':
                    printf("%c", j == 0 || j == 6 || j == 1 || j == 5 || (j == 2 && i == 1) || (j == 4 && i == 1) ? '*' : ' ');
                    break;
                case 'N':
                    printf("%c", j == 0 || j == 6 || j == 1 || j == 5 || j == 2 && j == 4 ? '*' : ' ');
                    break;
                case 'O':
                    printf("%c", j == 0 || j == 6 || j == 1 || j == 5 || j == 2 || j == 4 ? '*' : ' ');
                    break;
                case 'P':
                    printf("%c", j == 0 || j == 6 || j == 3 || j == 1 || j == 2 ? '*' : ' ');
                    break;
                case 'Q':
                    printf("%c", j == 0 || j == 6 || j == 1 || j == 5 || j == 2 || j == 4 || (i == 4 && j == 3) ? '*' : ' ');
                    break;
                case 'R':
                    printf("%c", j == 0 || j == 6 || j == 3 || j == 1 || j == 2 || (i == 4 && j == 4) || (i == 3 && j == 5) ? '*' : ' ');
                    break;
                case 'S':
                    printf("%c", j == 0 || j == 6 || j == 1 || j == 2 || j == 3 || j == 5 ? '*' : ' ');
                    break;
                case 'T':
                    printf("%c", j == 0 || i == 0 ? '*' : ' ');
                    break;
                case 'U':
                    printf("%c", j == 0 || j == 6 || j == 1 || j == 5 || (i == 4 && j == 2) || (i == 4 && j == 4) ? '*' : ' ');
                    break;
                case 'V':
                    printf("%c", j == 0 || j == 6 || (j == i && i <= 3) || (j == 6-i && i <= 3) ? '*' : ' ');
                    break;
                case 'W':
                    printf("%c", j == 0 || j == 6 || (j == i && i <= 3) || (j == 6-i && i <= 3) || (i == 4 && j == 3) || (i == 4 && j == 4) ? '*' : ' ');
                    break;
                case 'X':
                    printf("%c", j == 0 || j == 6 || (i == j && i <= 3) || (i == 6-j && i <= 3) ? '*' : ' ');
                    break;
                case 'Y':
                    printf("%c", j == 0 || j == 6 || (j == i && i <= 2) || (j == 4 && i >= 3) || (j == 2 && i >= 3) ? '*' : ' ');
                    break;
                case 'Z':
                    printf("%c", j == 0 || j == 6 || (i == 6-j && i <= 3) ? '*' : ' ');
                    break;
                case ' ':
                    printf("  ");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    char text[100];
    printf("Enter the text you want to convert to ASCII art: ");
    fgets(text, 100, stdin);
    printf("\n");
    text_art(text);
    return 0;
}