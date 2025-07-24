//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: protected
#include <stdio.h>

int main() {
    char text[100];
    printf("Enter your text: ");
    scanf("%[^\n]", text);
    
    char ascii[8][100];
    int i, j, k;
    for (i = 0; i < 8; i++) {
        for (j = 0, k = 0; text[k]; j++, k++) {
            switch (text[k]) {
                case 'A':
                    ascii[i][j] = (i == 0 || i == 4) ? '*' : ' ';
                    break;
                case 'B':
                    ascii[i][j] = (i == 0 || i == 3 || i == 7) ? '*' : ' ';
                    break;
                case 'C':
                    ascii[i][j] = (i == 0 || i == 7) ? '*' : ' ';
                    break;
                case 'D':
                    ascii[i][j] = (i == 0 || i == 7 || (i >= 1 && i <= 6 && j == 7)) ? '*' : ' ';
                    break;
                case 'E':
                    ascii[i][j] = (i == 0 || i == 3 || i == 4 || i == 7) ? '*' : ' ';
                    break;
                case 'F':
                    ascii[i][j] = (i == 0 || i == 3 || i == 4) ? '*' : ' ';
                    break;
                case 'G':
                    ascii[i][j] = (i == 0 || i == 3 || i == 4 || (i >= 1 && i <= 5 && j == 0) || (i >= 5 && j == 7)) ? '*' : ' ';
                    break;
                case 'H':
                    ascii[i][j] = (i == 3 || i == 4 || j == 0 || j == 7) ? '*' : ' ';
                    break;
                case 'I':
                    ascii[i][j] = (i == 0 || i == 7 || j == 3) ? '*' : ' ';
                    break;
                case 'J':
                    ascii[i][j] = (i == 0 || (i >= 6 && i <= 7 && j >= 1 && j <= 5) || (i >= 1 && j == 6) || (i >= 2 && j == 0)) ? '*' : ' ';
                    break;
                case 'K':
                    ascii[i][j] = (i == 3 || i == 4 || j == 0 || (i == j + 3)) ? '*' : ' ';
                    break;
                case 'L':
                    ascii[i][j] = (i == 7 || j == 0) ? '*' : ' ';
                    break;
                case 'M':
                    ascii[i][j] = ((i >= 0 && i <= 2 && j <= 2) || (i == j) || (i >= 0 && i <= 2 && j >= 5)) ? '*' : ' ';
                    break;
                case 'N':
                    ascii[i][j] = (i == j || j == 7 || i == 0 || i == 7) ? '*' : ' ';
                    break;
                case 'O':
                    ascii[i][j] = ((i == 0 || i == 7) && (j >= 1 && j <= 6)) || ((j == 0 || j == 7) && (i >= 1 && i <= 6)) ? '*' : ' ';
                    break;
                case 'P':
                    ascii[i][j] = (i == 0 || i == 3 || (j == 0 && i <= 3) || (j == 7 && i >= 4)) ? '*' : ' ';
                    break;
                case 'Q':
                    ascii[i][j] = ((i == 0 || i == 7) && (j >= 1 && j <= 6)) || ((j == 0 || j == 7) && (i >= 1 && i <= 6)) || (i == 5 && j == 5) || (i == 6 && j == 6) ? '*' : ' ';
                    break;
                case 'R':
                    ascii[i][j] = (i == 0 || i == 3 || (j == 0 && i <= 3) || (j == 7 && i >= 4) || (i == j + 3)) ? '*' : ' ';
                    break;
                case 'S':
                    ascii[i][j] = ((i == 0 || i == 3 || i == 7) && j >= 1 && j <= 6) || (i == 1 && j == 0) || (i == 2 && j == 7) || (i == 6 && j == 0) || (i == 5 && j == 7) ? '*' : ' ';
                    break;
                case 'T':
                    ascii[i][j] = (i == 0 || j == 3) ? '*' : ' ';
                    break;
                case 'U':
                    ascii[i][j] = ((j == 0 || j == 7) && i >= 1 && i <= 6) || (i == 7 && j >= 1 && j <= 6) ? '*' : ' ';
                    break;
                case 'V':
                    ascii[i][j] = ((i >= 0 && i <= 3 && j == i) || (i >= 0 && i <= 3 && j == 7 - i)) ? '*' : ' ';
                    break;
                case 'W':
                    ascii[i][j] = ((i >= 0 && i <= 2 && j <= 2) || (i == 3 && j == 3) || (i == 4 && j == 4) || (i >= 0 && i <= 2 && j >= 5) || (i == j + 3) || (i == 7 - j + 3)) ? '*' : ' ';
                    break;
                case 'X':
                    ascii[i][j] = (i == j || j == 7 - i) ? '*' : ' ';
                    break;
                case 'Y':
                    ascii[i][j] = ((i >= 0 && i <= 3 && j == i) || (i >= 0 && i <= 3 && j == 7 - i) || (i >= 4 && i <= 7 && j == 3)) ? '*' : ' ';
                    break;
                case 'Z':
                    ascii[i][j] = (i == 0 || i == 7 || i + j == 7) ? '*' : ' ';
                    break;
                case ' ':
                    ascii[i][j] = ' ';
                    break;
                default:
                    ascii[i][j] = '?';
                }
            }
        ascii[i][j] = '\0';
    }
    
    for (i = 0; i < 8; i++) {
        printf("%s\n", ascii[i]);
    }
    
    return 0;
}