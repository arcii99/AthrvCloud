//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: puzzling
#include <stdio.h>

void drawTriangle(int base, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<base; j++) {
            if(j==0 || i==height-1 || i==j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int base, height;
    printf("Enter the base of the triangle: ");
    scanf("%d", &base);
    printf("Enter the height of the triangle: ");
    scanf("%d", &height);
    printf("\nThe triangle with dimensions %d x %d:\n", base, height);
    drawTriangle(base, height);
    return 0;
}