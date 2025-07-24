//FormAI DATASET v1.0 Category: Robot movement control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x_pos = 0;
    int y_pos = 0;
    srand(time(NULL));

    printf("Starting coordinates: (%d, %d)\n", x_pos, y_pos);

    for (int i = 0; i < 50; i++) {
        int direction = rand() % 4; // 0 = north, 1 = east, 2 = south, 3 = west

        switch (direction) {
            case 0:
                printf("Moving north.\n");
                y_pos++;
                break;
            case 1:
                printf("Moving east.\n");
                x_pos++;
                break;
            case 2:
                printf("Moving south.\n");
                y_pos--;
                break;
            case 3:
                printf("Moving west.\n");
                x_pos--;
                break;
            default:
                break;
        }

        printf("Current coordinates: (%d, %d)\n", x_pos, y_pos);
    }

    printf("Final coordinates: (%d, %d)\n", x_pos, y_pos);

    return 0;
}