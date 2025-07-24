//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>

// Function to move disk from source to destination tower
void moveDisk(char source, char dest, int disk_num) {
    printf("Move disk %d from %c to %c\n", disk_num, source, dest);
}

// Function to solve Tower of Hanoi problem
void solveTowerOfHanoi(int num_disks, char source, char aux, char dest) {
    
    // Base case: When there is only one disk to be moved
    if(num_disks == 1) {
        moveDisk(source, dest, 1);
        return;
    }
    
    // Recursive case: Move (num_disks-1) disks from source to aux tower
    solveTowerOfHanoi(num_disks-1, source, dest, aux);
    
    // Move the remaining disk from source to destination tower
    moveDisk(source, dest, num_disks);
    
    // Move (num_disks-1) disks from aux to destination tower
    solveTowerOfHanoi(num_disks-1, aux, source, dest);
}

// Main function
int main() {
    
    // Get input from user
    printf("Enter the number of disks: ");
    int num_disks;
    scanf("%d", &num_disks);
    
    // Error handling: Tower of Hanoi is not solvable for less than 1 disk
    if(num_disks < 1) {
        printf("Invalid number of disks!\n");
        return 0;
    }
    
    printf("\nSolving Tower of Hanoi problem for %d disks...\n\n", num_disks);
    
    // Call solveTowerOfHanoi function to solve the problem
    solveTowerOfHanoi(num_disks, 'A', 'B', 'C');
    
    printf("\nCongratulations! Tower of Hanoi problem successfully solved!\n");
    
    return 0;
}