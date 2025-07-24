//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>

// recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char destination){
    if (n == 1) { // base case: move the single disk from source to destination
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    // move (n-1) disks from source to auxiliary, using destination as a temporary
    towerOfHanoi(n-1, source, destination, auxiliary);
    // move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    // move (n-1) disks from auxiliary to destination, using source as a temporary
    towerOfHanoi(n-1, auxiliary, source, destination);
}

int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The steps to solve the Tower of Hanoi problem with %d disks are:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}