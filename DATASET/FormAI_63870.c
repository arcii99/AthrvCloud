//FormAI DATASET v1.0 Category: Robot movement control ; Style: cheerful
// Welcome to our cheerful C Robot movement program!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // set random seed based on current time
    int dir = rand() % 4; // choose random starting direction (0-3)
    int x = 0, y = 0; // initialize position to (0, 0)
    printf("The C Robot is ready to move! Starting position: (%d, %d)\n", x, y);

    // loop 10 times
    for (int i = 0; i < 10; i++) {
        // choose random integer to determine movement distance (1-5)
        int dist = rand() % 5 + 1;
        printf("Moving %d units...\n", dist);

        // update position based on current direction
        switch (dir) {
            case 0: // up
                y += dist;
                break;
            case 1: // right
                x += dist;
                break;
            case 2: // down
                y -= dist;
                break;
            case 3: // left
                x -= dist;
                break;
        }

        printf("Position after move #%d: (%d, %d)\n", i+1, x, y);

        // choose random integer to determine new direction (0-3)
        int new_dir = rand() % 4;
        // make sure new direction is not the opposite of current direction
        while (new_dir == dir || new_dir == (dir + 2) % 4) {
            new_dir = rand() % 4;
        }
        dir = new_dir; // update direction for next move
        // output a cheerful message based on new direction
        switch (dir) {
            case 0: // up
                printf("Going up next! :)\n");
                break;
            case 1: // right
                printf("Going right next! :D\n");
                break;
            case 2: // down
                printf("Going down next! ^_^\n");
                break;
            case 3: // left
                printf("Going left next! :P\n");
                break;
        }
    }

    printf("The C Robot has finished its moves. Final position: (%d, %d)\n", x, y);
    printf("Goodbye! :)\n");

    return 0;
}