//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: optimized
#include <stdio.h>

// function to move disk from one tower to another tower
void move_disk(char from_tower, char to_tower, int disk) {
    printf("Move disk %d from %c to %c\n", disk, from_tower, to_tower);
}

// function to solve the Tower of Hanoi problem
void tower_of_hanoi(int num_disks, char from_tower, char to_tower, char aux_tower) {
    if (num_disks == 1) {
        move_disk(from_tower, to_tower, num_disks);
        return;
    }
    
    // move n-1 disks from source tower to auxiliary tower
    tower_of_hanoi(num_disks - 1, from_tower, aux_tower, to_tower);
    
    // move remaining last disk from source tower to destination tower
    move_disk(from_tower, to_tower, num_disks);
    
    // move n-1 disks from auxiliary tower to destination tower
    tower_of_hanoi(num_disks - 1, aux_tower, to_tower, from_tower);
}

int main() {
    int num_disks = 4;
    tower_of_hanoi(num_disks, 'A', 'C', 'B');
    return 0;
}