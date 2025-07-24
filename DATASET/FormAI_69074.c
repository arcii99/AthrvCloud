//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: excited
#include <stdio.h>

// Excited Pathfinding Algorithm in C!
int main() {
    printf("I'm so excited to show you my awesome pathfinding algorithm!!\n");

    // First, let's get the map and the start and end points
    int map[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    
    int start_x = 1;
    int start_y = 1;
    int end_x = 8;
    int end_y = 7;

    // Let's find the path using our algorithm
    int current_x = start_x;
    int current_y = start_y;
    int steps = 0;
    while (current_x != end_x || current_y != end_y) {
        steps++;
        
        // Check all four directions
        if (map[current_y][current_x - 1] == 0) {
            printf("Step %d: Going left\n", steps);
            current_x--;
        } else if (map[current_y - 1][current_x] == 0) {
            printf("Step %d: Going up\n", steps);
            current_y--;
        } else if (map[current_y][current_x + 1] == 0) {
            printf("Step %d: Going right\n", steps);
            current_x++;
        } else if (map[current_y + 1][current_x] == 0) {
            printf("Step %d: Going down\n", steps);
            current_y++;
        } else {
            printf("I'm stuck!!\n");
            break;
        }
    }

    printf("Yay! I found the end in %d steps!!\n", steps);

    return 0;
}