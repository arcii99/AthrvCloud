//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: surrealist
#include <stdio.h>

int main() {
    printf("Welcome to the Surrealist ASCII Art Generator!\n");
    printf("Please enter your desired ASCII character: ");
    char character;
    scanf("%c", &character);
    printf("Please enter the amount of rows you want in your ASCII art: ");
    int rows;
    scanf("%d", &rows);
    printf("Please enter the amount of columns you want in your ASCII art: ");
    int columns;
    scanf("%d", &columns);
    printf("\n");

    // Generate the ASCII art
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (i == j) {
                printf("%c", character);
            } else if (i + j == rows - 1) {
                printf("%c", character);
            } else if (i < j && i + j < rows - 1) {
                printf("%c", character + i + j);
            } else if (i < j && i + j >= rows) {
                printf("%c", character + (rows - i - 1) + (columns - j - 1));
            } else if (i >= j && i + j >= rows) {
                printf("%c", character + (rows - i - 1) + (j - columns + 1));
            } else {
                printf("%c", character + (columns - j - 1) + i);
            }
        }
        printf("\n");
    }

    return 0;
}