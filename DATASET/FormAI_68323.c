//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n;
    printf("Enter the size of the square: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("The size of the square must be odd.");
        return 0;
    }

    int arr[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }

    int x = n/2;
    int y = n-1;

    for (i = 1; i <= n*n; i++) {
        if (x == -1 && y == n) { // Case 1 
            x = 0;
            y = n-2;
        } else {
            if (y == n) { // Row is above the matrix
                y = 0;
            }
            if (x < 0) { // Column is below the matrix
                x = n - 1;
            }
        }
        if (arr[x][y]) { // Case 2
            x++;
            y -= 2;
            continue;
        } else {
            arr[x][y] = i;
        }
        x--;
        y++;
    }

    printf("The Magic Square for n=%d:\nSum of each row or column %d:\n\n",
            n, (n * (n * n + 1)) / 2);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}