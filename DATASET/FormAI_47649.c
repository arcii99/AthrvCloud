//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Alan Touring
#include<stdio.h>

int main() {
    int floors, cur_floor, dest_floor, next_floor;
    char direction;
    printf("Enter the number of floors in the building: ");
    scanf("%d", &floors);
    printf("Enter the current floor: ");
    scanf("%d", &cur_floor);
    printf("Enter the destination floor: ");
    scanf("%d", &dest_floor);
    
    if(cur_floor < dest_floor) {
        direction = 'U';
        next_floor = cur_floor + 1;
    } else {
        direction = 'D';
        next_floor = cur_floor - 1;
    }
    printf("The elevator is currently going %c from floor %d to %d...\n", direction, cur_floor, next_floor);
    while(next_floor != dest_floor) {
        if(next_floor < dest_floor) {
            next_floor++;
        } else {
            next_floor--;
        }
        printf("The elevator is currently going %c from floor %d to %d...\n", direction, cur_floor, next_floor);
    }
    printf("The elevator has reached its destination of floor %d. Have a nice day!\n", dest_floor);
    
    return 0;
}