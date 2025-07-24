//FormAI DATASET v1.0 Category: Smart home light control ; Style: recursive
#include<stdio.h>

void lightOn(int floor, int room) {
    printf("Floor %d, Room %d: Light is on!\n", floor, room);
}

void lightOff(int floor, int room) {
    printf("Floor %d, Room %d: Light is off!\n", floor, room);
}

void recursiveControl(int floors, int rooms) {
    if(floors == 0 && rooms == 0)
        return;
    else if(rooms == 0) {
        recursiveControl(floors-1, rooms+3);
    }
    else if(rooms % 2 == 1) {
        lightOn(floors, rooms);
        recursiveControl(floors, rooms-1);
    }
    else {
        lightOff(floors, rooms);
        recursiveControl(floors, rooms-1);
    }
}

int main() {
    int floors = 3;
    int rooms = 5;

    recursiveControl(floors, rooms);
    
    return 0;
}