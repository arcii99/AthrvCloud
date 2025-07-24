//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: surrealist
#include <stdio.h>

int main() {
    printf("Welcome to the Surrealist ASCII Art Generator!\n");
    printf("\n");

    int width, height;
    printf("Enter the width of your art (recommended: 50-100): ");
    scanf("%d", &width);
    printf("Enter the height of your art (recommended: 10-20): ");
    scanf("%d", &height);
    printf("\n");

    char colors[10] = {'#', '@', '%', '&', '*', '+', '=', '-', '$'};

    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int random_color = rand() % 10;
            printf("%c ", colors[random_color]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Your Surrealist ASCII Art has been generated!\n");

    return 0;
}