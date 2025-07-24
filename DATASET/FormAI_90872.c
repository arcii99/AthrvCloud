//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_art(int width, int height) {
    char symbols[] = {'#','$','%','&','*','+','-','@'};
    int num_symbols = sizeof(symbols)/sizeof(symbols[0]);
    int grid[height][width];
    int max_num = num_symbols - 1;
    int min_num = 0;
    srand(time(NULL));
    
    // Fill the grid with randomly generated symbols
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            grid[i][j] = (rand() % (max_num - min_num + 1)) + min_num;
        }
    }
    
    // Display the generated art
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            printf("%c", symbols[grid[i][j]]);
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    
    printf("Enter the width and height of the art: ");
    scanf("%d %d", &width, &height);
    
    generate_art(width, height);
    
    return 0;
}