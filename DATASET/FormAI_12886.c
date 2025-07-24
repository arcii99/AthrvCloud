//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>

void fibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci sequence up to %d:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d, ", t1); // print current term
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}

void drawFibonacci(int n) {
    int arr[n][n];
    int x = 0, y = 0; // starting coordinates
    int direction = 0; // 0 - right, 1 - down, 2 - left, 3 - up
    int currentFib = 1;
    arr[x][y] = currentFib;
    while (currentFib < n * n) {
        // move to next cell
        if (direction == 0) y++;
        else if (direction == 1) x++;
        else if (direction == 2) y--;
        else if (direction == 3) x--;
        // add next Fibonacci number to current cell
        currentFib++;
        arr[x][y] = currentFib;
        // check if direction needs to be changed
        if (direction == 0 && (y == n-1 || arr[x][y+1] != 0)) direction = 1;
        else if (direction == 1 && (x == n-1 || arr[x+1][y] != 0)) direction = 2;
        else if (direction == 2 && (y == 0 || arr[x][y-1] != 0)) direction = 3;
        else if (direction == 3 && (x == 0 || arr[x-1][y] != 0)) direction = 0;
    }
    // print the resulting array
    printf("\nFibonacci spiral: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter a number (n) to generate Fibonacci sequence up to n and a Fibonacci spiral with sides of length n: ");
    scanf("%d", &n);
    fibonacci(n);
    drawFibonacci(n);
    return 0;
}