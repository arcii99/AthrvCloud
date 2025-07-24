//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: creative
#include <stdio.h>

int disk, source, auxiliary, destination, steps = 0;

void hanoi(int disk, int source, int auxiliary, int destination) {
    if (disk == 1) {
        printf("\nStep %d: Moved disk 1 from peg %d to peg %d", ++steps, source, destination);
        return;
    }

    hanoi(disk - 1, source, destination, auxiliary);

    printf("\nStep %d: Moved disk %d from peg %d to peg %d", ++steps, disk, source, destination);

    hanoi(disk - 1, auxiliary, source, destination);
}

int main(){
    printf("Welcome to the Tower of Hanoi problem!\n");
    printf("Please enter the number of disks: ");
    scanf("%d", &disk);

    printf("\nThe solution for the Tower of Hanoi problem with %d disks is: \n", disk);
    hanoi(disk, 1, 2, 3);

    printf("\nTotal number of moves: %d", steps);
    return 0;
}