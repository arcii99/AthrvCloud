//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define ROWS 20 // number of rows in the animation
#define COLS 80 // number of columns in the animation

// function to compute the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    // initialize animation
    bool grid[ROWS][COLS] = { false };
    int x = 0;
    int y = 0;

    // loop through Fibonacci sequence and update animation
    for (int i = 0; i < ROWS*COLS; i++) {
        int value = fibonacci(i);
        x++;
        if (x >= COLS) {
            x = 0;
            y++;
        }
        if (y >= ROWS) {
            y = 0;
            usleep(50000); // pause animation for 0.05 seconds
            system("clear"); // clear terminal screen
            for (int j = 0; j < ROWS; j++) {
                for (int k = 0; k < COLS; k++) {
                    printf("%c", grid[j][k] ? '#' : ' ');
                }
                printf("\n");
            }
        }
        if (value % 2 == 0) {
            grid[y][x] = true;
        } else {
            grid[y][x] = false;
        }
    }

    return 0;
}