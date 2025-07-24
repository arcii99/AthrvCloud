//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>

//function to move the disks from source peg to destination peg
void moveDisk(int source, int destination){
    printf("Move disk from Peg %d to Peg %d\n", source, destination);
}

//function to solve the tower of hanoi problem
void towerOfHanoi(int n, int source, int auxiliary, int destination){

    if (n == 1){
        moveDisk(source, destination);  //move the disk from source to destination
        return;
    }
    towerOfHanoi(n-1, source, destination, auxiliary);
    moveDisk(source, destination);  //move the largest disk from source to destination
    towerOfHanoi(n-1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 1, 2, 3);
    return 0;
}