//FormAI DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT -1
#define RIGHT 1

void move(int distance, int direction, int turn){
    printf("Moving %d units %swards and turning %s\n", abs(distance), (direction == FORWARD) ? "for" : "back",
            (turn == LEFT) ? "left" : "right");
}

int main(){
    int dist = 10;
    
    printf("Starting Robot Movement Control Program\n");
    
    move(dist, FORWARD, RIGHT);
    move(dist, BACKWARD, LEFT);
    move(dist, FORWARD, LEFT);
    move(dist, BACKWARD, RIGHT);
    
    printf("Finishing Robot Movement Control Program\n");

    return 0;
}