//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int pixelWidth, pixelHeight;
    int i, j, k;
    char pixelChar[10];
    srand(time(NULL));
    
    printf("Enter the width of the pixel art: ");
    scanf("%d", &pixelWidth);
    printf("Enter the height of the pixel art: ");
    scanf("%d", &pixelHeight);
    
    printf("Enter 10 pixel characters: ");
    for(i = 0; i < 10; i++) {
        scanf(" %c", &pixelChar[i]);
    }
    
    for(i = 0; i < pixelHeight; i++) {
        for(j = 0; j < pixelWidth; j++) {
            k = rand() % 10;
            printf("%c", pixelChar[k]);
        }
        printf("\n");
    }
    return 0;
}