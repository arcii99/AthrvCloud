//FormAI DATASET v1.0 Category: Fractal Generation ; Style: realistic
#include <stdio.h>

//recursive function for generating fractal
void fractal(int x, int y, int len) {
    if(len <= 1) {
        printf("Line from (%d, %d) to (%d, %d)\n", x, y, x, y);
        return;
    }
    fractal(x, y, len/3);
    fractal(x+len*2/3, y, len/3);
    fractal(x+len/3, y+len/3, len/3);
    fractal(x, y+len*2/3, len/3);
    fractal(x+len*2/3, y+len*2/3, len/3);
}

int main() {
    int length;
    printf("Enter the length of the fractal: ");
    scanf("%d", &length);
    fractal(0, 0, length);

    return 0;
}