//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40

/* This program generates ASCII art from user input text */

void generate_art(char* text) {
    int i, j, k;
    int matrix[HEIGHT][WIDTH];
    int row = 0, col = 0;
    int len = strlen(text);

    // Initialize matrix with spaces
    for(i = 0; i < HEIGHT; i++)
        for(j = 0; j < WIDTH; j++)
            matrix[i][j] = ' ';

    // Populate matrix with characters from input text
    for(k = 0; k < len; k++) {
        if(col >= WIDTH) {
            col = 0;
            row++;
        }
        if(row >= HEIGHT) break;
        matrix[row][col++] = text[k];
    }
    
    // Generate ASCII art from matrix
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char text[100];
    printf("Enter text: ");
    scanf("%[^\n]", text);
    generate_art(text);
    return 0;
}