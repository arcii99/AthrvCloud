//FormAI DATASET v1.0 Category: Robot movement control ; Style: high level of detail
#include <stdio.h>

int main() {
    int direction = 0; // 0 = up, 1 = right, 2 = down, 3 = left
    int x = 0;
    int y = 0;
    
    printf("Starting position: (%d,%d)\n", x, y);
    
    // Move forward 5 times
    for (int i = 0; i < 5; i++) {
        switch (direction) {
            case 0: // Moving up
                y += 1;
                break;
            case 1: // Moving right
                x += 1;
                break;
            case 2: // Moving down
                y -= 1;
                break;
            case 3: // Moving left
                x -= 1;
                break;
        }
        printf("Movinig forward... Current position: (%d,%d)\n", x, y);
    }

    // Turn right and move forward 3 more times
    direction = 1;
    for (int i = 0; i < 3; i++) {
        switch (direction) {
            case 0: // Moving up
                y += 1;
                break;
            case 1: // Moving right
                x += 1;
                break;
            case 2: // Moving down
                y -= 1;
                break;
            case 3: // Moving left
                x -= 1;
                break;
        }
        printf("Movinig forward... Current position: (%d,%d)\n", x, y);
    }
    
    // Turn around and move backward 2 times
    direction = 2;
    for (int i = 0; i < 2; i++) {
        switch (direction) {
            case 0: // Moving up
                y -= 1;
                break;
            case 1: // Moving right
                x -= 1;
                break;
            case 2: // Moving down
                y += 1;
                break;
            case 3: // Moving left
                x += 1;
                break;
        }
        printf("Movinig backward... Current position: (%d,%d)\n", x, y);
    }
    
    // Turn left and move forward 4 more times
    direction = 3;
    for (int i = 0; i < 4; i++) {
        switch (direction) {
            case 0: // Moving up
                y += 1;
                break;
            case 1: // Moving right
                x += 1;
                break;
            case 2: // Moving down
                y -= 1;
                break;
            case 3: // Moving left
                x -= 1;
                break;
        }
        printf("Movinig forward... Current position: (%d,%d)\n", x, y);
    }

    return 0;
}