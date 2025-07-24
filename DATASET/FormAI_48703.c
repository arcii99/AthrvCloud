//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include <stdio.h>

int main() {
    char characters[] = {'#', '@', 'O', 'o', '+', '-', '=', '*'};
    int rows, cols;
    printf("Welcome to the ASCII art generator!\n");
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("\n");

    int index = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%c ", characters[index]);
            index++;
            if (index == 8) {
                index = 0;
            }
        }
        printf("\n");
    }

    printf("\n");
    printf("Voila! Your ASCII art is ready!\n");
    printf("Don't forget to share it with your friends!\n");

    return 0;
}