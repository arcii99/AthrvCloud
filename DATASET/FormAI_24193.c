//FormAI DATASET v1.0 Category: Robot movement control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int n);

int main() {
    srand(time(0));
    int robot_x = 0, robot_y = 0, dest_x = 5, dest_y = 7;
    while(robot_x != dest_x || robot_y != dest_y) {
        int dx = dest_x - robot_x;
        int dy = dest_y - robot_y;
        if(dx > 0) {
            printf("Moving right...\n");
            robot_x++;
        } else if(dx < 0) {
            printf("Moving left...\n");
            robot_x--;
        }

        if(dy > 0) {
            printf("Moving up...\n");
            robot_y++;
        } else if(dy < 0) {
            printf("Moving down...\n");
            robot_y--;
        }

        int r = rand() % 20;
        if(r > 15) {
            printf("Obstacle detected, turning left...\n");
            delay(1000);
            int new_dx, new_dy;
            if(dx > 0) {
                new_dx = 0;
                new_dy = -1;
            } else if(dx < 0) {
                new_dx = 0;
                new_dy = 1;
            } else if(dy > 0) {
                new_dx = -1;
                new_dy = 0;
            } else {
                new_dx = 1;
                new_dy = 0;
            }
            dest_x = robot_x + new_dx;
            dest_y = robot_y + new_dy;
            printf("New destination: (%d,%d)\n", dest_x, dest_y);
        }

        delay(500);
    }

    printf("Arrived at destination!\n");

    return 0;
}

void delay(int n) {
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<100000;j++);
}