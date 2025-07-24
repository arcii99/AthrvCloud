//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int battery;
} Vehicle; 

void move(Vehicle *v, char direction) {
    if (direction == 'w') {
        v->pos.y += 1;
    } else if (direction == 'a') {
        v->pos.x -= 1;
    } else if (direction == 's') {
        v->pos.y -= 1;
    } else if (direction == 'd') {
        v->pos.x += 1;
    } else {
        printf("Invalid direction input\n");
        return;
    }
    // reduce battery by 1
    v->battery -= 1;
}

int main() {
    srand(time(NULL));
    Vehicle v = {{0, 0}, 50};
    char input;
    
    while (v.battery > 0) {
        printf("Current position: (%d, %d)\n", v.pos.x, v.pos.y);
        printf("Battery remaining: %d\n", v.battery);
        
        // randomly generates a direction for player to move
        int dir_num = rand() % 4;
        if (dir_num == 0) {
            printf("Enter 'w' to move up.\n");
            input = getchar();
            move(&v, input);
        } else if (dir_num == 1) {
            printf("Enter 'a' to move left.\n");
            input = getchar();
            move(&v, input);
        } else if (dir_num == 2) {
            printf("Enter 's' to move down.\n");
            input = getchar();
            move(&v, input);
        } else if (dir_num == 3) {
            printf("Enter 'd' to move right.\n");
            input = getchar();
            move(&v, input);
        }
        
        // clears input buffer
        while ((getchar()) != '\n');
    }
    
    printf("Battery ran out. Game over.\n");
    
    return 0;
}