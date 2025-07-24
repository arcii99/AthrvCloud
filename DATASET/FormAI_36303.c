//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the number of pixels in each dimension: ");
    scanf("%d", &n);

    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = round(sin(i) + cos(j));
        }
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}