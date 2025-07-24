//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: grateful
#include <stdio.h>

// This program generates a geometric pattern of asterisks using mathematical equations!

void draw_pattern(int n) {
    int i, j;
    float x, y;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            x = (float) i / n - 0.5;
            y = (float) j / n - 0.5;
            if (x * x + y * y <= 0.25 && x * x - y * y <= 0.2) {
                printf("* ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Welcome to the Geometric Pattern Maker!\n");
    printf("Enter the number of rows (between 5 to 30) : ");
    scanf("%d", &n);
    if (n < 5 || n > 30) {
        printf("Invalid input! Please enter a number between 5 to 30.\n");
    }
    else {
        draw_pattern(n);
    }
    return 0;
}