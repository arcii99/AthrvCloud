//FormAI DATASET v1.0 Category: Robot movement control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int x = 0, y = 0;
int move_left();
int move_right();
int move_forward();
int move_backward();

int main() {
    srand(time(NULL));
    int count = 0;
    while (count < 10) {
        int rand_num = rand() % 4;

        switch (rand_num) {
            case 0:
                if (move_left()) {
                    printf("Moved left\n");
                    x--;
                } 
                break;
            case 1:
                if (move_right()) {
                    printf("Moved right\n");
                    x++;
                }
                break;
            case 2:
                if (move_forward()) {
                    printf("Moved forward\n");
                    y++;
                }
                break;
            case 3:
                if (move_backward()) {
                    printf("Moved backward\n");
                    y--;
                }
                break;
        }

        count++;
        printf("Current position: (%d,%d)\n\n", x, y);
    }

    printf("Movement completed.\n");
    return 0;
}

int move_left() {
    // Check if movement is valid
    if (x - 1 < 0) {
        printf("Invalid move left\n");
        return 0;
    }

    // Movement is valid, return 1
    return 1;
}

int move_right() {
    // Check if movement is valid
    if (x + 1 > 10) {
        printf("Invalid move right\n");
        return 0;
    }

    // Movement is valid, return 1
    return 1;
}

int move_forward() {
    // Check if movement is valid
    if (y + 1 > 10) {
        printf("Invalid move forward\n");
        return 0;
    }

    // Movement is valid, return 1
    return 1;
}

int move_backward() {
    // Check if movement is valid
    if (y - 1 < 0) {
        printf("Invalid move backward\n");
        return 0;
    }

    // Movement is valid, return 1
    return 1;
}