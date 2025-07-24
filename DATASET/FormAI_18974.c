//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: brave
#include<stdio.h>

// Function to move disk from source tower to destination tower
void move_disk(char source, char destination) {
    printf("Move disk from %c to %c\n", source, destination);
}

// Recursive function to solve Tower of Hanoi problem
void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    if(n == 1) {
        move_disk(source, destination);
        return;
    }
    
    tower_of_hanoi(n-1, source, auxiliary, destination);
    move_disk(source, destination);
    tower_of_hanoi(n-1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter number of disks\n");
    scanf("%d", &n);

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}