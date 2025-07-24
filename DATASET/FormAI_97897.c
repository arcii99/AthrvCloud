//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>

// function prototype
void tower_of_hanoi(int, int, int, int);

int main() {
    int num_disks = 3; // default value
    int num_pegs = 3; // default value
    
    // prompt user to input number of disks
    printf("Enter number of disks: ");
    scanf("%d", &num_disks);
    
    // prompt user to input number of pegs
    printf("Enter number of pegs: ");
    scanf("%d", &num_pegs);
    
    // print initial configuration
    printf("\nInitial Configuration\n");
    printf("---------------------\n\n");
    printf("Number of Disks: %d\n", num_disks);
    printf("Number of Pegs: %d\n\n", num_pegs);
    
    // compute and print minimum number of moves required
    int num_moves = (1 << num_disks) - 1;
    printf("Minimum Number of Moves Required: %d\n\n", num_moves);

    // solve tower of hanoi problem and print each move
    printf("Moves:\n\n");
    tower_of_hanoi(num_disks, 1, num_pegs, 3);
    
    return 0;
}

// recursive function to solve tower of hanoi problem
void tower_of_hanoi(int num_disks, int start_peg, int end_peg, int aux_peg) {
    if (num_disks == 1) {
        printf("Move Disk 1 from Peg %d to Peg %d\n", start_peg, end_peg);
        return;
    }

    tower_of_hanoi(num_disks - 1, start_peg, aux_peg, end_peg);
    printf("Move Disk %d from Peg %d to Peg %d\n", num_disks, start_peg, end_peg);
    tower_of_hanoi(num_disks - 1, aux_peg, end_peg, start_peg);
}