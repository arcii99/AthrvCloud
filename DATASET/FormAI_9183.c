//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int move_count = 0; // Variable to count number of moves

void moveDisc(int n, char source, char destination, char auxiliary) {
    if(n == 1) {
        printf("Move disc 1 from %c to %c\n", source, destination);
        move_count++;
        return;
    }
    moveDisc(n-1, source, auxiliary, destination);
    printf("Move disc %d from %c to %c\n", n, source, destination);
    move_count++;
    moveDisc(n-1, auxiliary, destination, source);
}

int main() {
    int n, i;
    printf("Welcome to the Tower of Hanoi Simulator! In this cyberpunk world, you must help hacker Neo move disks from Tower A to Tower C.\n");

    while(1) {
        printf("Enter number of disks (minimum 3): ");
        scanf("%d", &n);
        if(n<3) {
            printf("Invalid input! Please enter a number of 3 or higher.\n");
            continue;
        } else {
            break;
        }
    }

    moveDisc(n, 'A', 'C', 'B');
    printf("Completed in %d moves.", move_count);

    return 0;
}