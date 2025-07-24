//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include<stdio.h>

// Recursive function to solve Tower of Hanoi problem
void tower_of_hanoi(int n, char source, char auxiliary, char destination){
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", source, destination);
        return;
    }
    tower_of_hanoi(n-1, source, destination, auxiliary);
    printf("\n Move disk %d from rod %c to rod %c", n, source, destination);
    tower_of_hanoi(n-1, auxiliary, source, destination);
}

int main(){
    int n; // Number of disks
    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Ensuring that the number of disks is not less than 3
    while(n<3){
        printf("Error! Number of disks should be at least 3.\n");
        printf("Enter number of disks: ");
        scanf("%d", &n);
    }

    // Printing the instructions for the user
    printf("\n\nInstructions: ");
    printf("\nRod A is the starting rod with all disks.");
    printf("\nRod C should have the similar order of disks as rod A.");
    printf("\nYou can transfer one disk at a time from a rod to another rod.");
    printf("\nA larger disk can never be placed on the smaller disk.");

    // Calling the recursive function to solve the Tower of Hanoi problem
    tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
}