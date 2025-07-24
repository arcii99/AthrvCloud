//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>

/* define the Tower of Hanoi function */
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if(n == 1) {
        printf("\nMove disk 1 from tower %c to tower %c", source, destination);
        return;
    }

    towerOfHanoi(n-1, source, destination, auxiliary);
    printf("\nMove disk %d from tower %c to tower %c", n, source, destination);
    towerOfHanoi(n-1, auxiliary, source, destination);
}

/* main function */
int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The steps to move %d disks from source to destination are:\n", n);

    /* call the Tower of Hanoi function */
    towerOfHanoi(n, 'A', 'B', 'C');
    printf("\n");

    return 0;
}