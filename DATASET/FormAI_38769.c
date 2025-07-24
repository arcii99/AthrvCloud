//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>

//Shape-shifting function to switch between solving the tower 
//of Hanoi problem recursively and iteratively
void solveTower(char source, char destination, char auxiliary, int numDisks) {
    if (numDisks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    //Switch to iterative solution if number of disks is odd
    if (numDisks % 2 == 1) {
        printf("\nSwitching to iterative solution...\n\n");
        
        int i, j = numDisks;
        char temp;
        while (1) {
            temp = destination;
            destination = auxiliary;
            auxiliary = temp;
            i = (--j % 3);
            if (i == 0) {
                if (destination < auxiliary) {
                    printf("Move disk %d from %c to %c\n", 1, source, destination);
                } else {
                    printf("Move disk %d from %c to %c\n", 1, source, auxiliary);
                }
            } else if (i == 1) {
                if (source < auxiliary) {
                    printf("Move disk %d from %c to %c\n", 1, source, auxiliary);
                } else {
                    printf("Move disk %d from %c to %c\n", 1, source, destination);
                }
            } else {
                if (source < destination) {
                    printf("Move disk %d from %c to %c\n", 1, auxiliary, source);
                } else {
                    printf("Move disk %d from %c to %c\n", 1, destination, source);
                }
            }
            if (j == 0) {
                break;
            }
        }
        return;
    }
    
    //Recursive solution for even number of disks
    solveTower(source, auxiliary, destination, numDisks - 1);
    printf("Move disk %d from %c to %c\n", numDisks, source, destination);
    solveTower(auxiliary, destination, source, numDisks - 1);
}

int main() {
    int numDisks = 4;
    char source = 'A', destination = 'C', auxiliary = 'B';
    printf("Solving the Tower of Hanoi problem with %d disks...\n\n", numDisks);
    solveTower(source, destination, auxiliary, numDisks);
    return 0;
}