//FormAI DATASET v1.0 Category: Fractal Generation ; Style: configurable
#include <stdio.h>

int main() {
    int fractal_width, fractal_depth;
    printf("Enter the width of the fractal: ");
    scanf("%d", &fractal_width);
    printf("Enter the depth of the fractal: ");
    scanf("%d", &fractal_depth);
    
    int x, y;
    for (y = 0; y < fractal_width; y++) {
        for (x = 0; x < fractal_width; x++) {
            int cx = x - fractal_width / 2;
            int cy = y - fractal_width / 2;
            int i;
            for (i = 0; i < fractal_depth; i++) {
                int temp_x = cx * cx - cy * cy + x - fractal_width / 2;
                int temp_y = 2 * cx * cy + y - fractal_width / 2;
                cx = temp_x;
                cy = temp_y;
                if (cx * cx + cy * cy > 4) {
                    break;
                }
            }
            if (i == fractal_depth) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}