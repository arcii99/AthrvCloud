//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Claude Shannon
#include <stdio.h>

// Function to generate the fractal
void fractal(int n, int offset) {
    if (n == 0) {
        return;
    }
    fractal(n - 1, offset);
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");
    for (int i = 0; i < offset; i++) {
        printf(" ");
    }
    fractal(n - 1, offset + n);
}

int main() {
    int n = 4; // Change this to adjust the size of the fractal
    fractal(n, 0);
    return 0;
}