//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ephemeral
#include<stdio.h>

// function to recursively solve the Tower of Hanoi problem
// n: number of disks
// source: tower from which the disks are to be moved
// auxiliary: tower to be used for moving the disks
// destination: tower to which the disks are to be moved
void tower_of_hanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 0)
        return;
    // move the top n-1 disks from source to auxiliary tower using destination tower
    tower_of_hanoi(n-1, source, destination, auxiliary);
    // move the nth disk from source to destination tower
    printf("Move disk %d from %c to %c\n", n, source, destination);
    // move the n-1 disks from auxiliary to destination tower using source tower
    tower_of_hanoi(n-1, auxiliary, source, destination);
}

// main function
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The solution of the Tower of Hanoi problem with %d disks is as follows:\n", n);
    tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
}