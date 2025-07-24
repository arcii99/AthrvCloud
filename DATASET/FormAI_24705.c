//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>

// Mind-bending Tower of Hanoi problem example program

int main() {
    int num_of_disks = 5; // Change this to test with different number of disks
    int num_of_moves = (1 << num_of_disks) - 1; // Total number of moves required to solve the problem (2^n - 1)

    printf("Welcome to the mind-bending Tower of Hanoi problem example program!\n\n");

    printf("The problem involves moving %d disks from one peg to another, using a third peg as auxiliary.\n", num_of_disks);
    printf("The goal of the problem is to move all the disks from the starting peg to the ending peg, one disk at a time, without placing a larger disk on top of a smaller one.\n");
    printf("The minimum number of moves required to solve this problem is %d.\n\n", num_of_moves);

    printf("Let's begin...\n\n");

    // Recursive function to solve Tower of Hanoi problem
    void solve_tower_of_hanoi(int num_of_disks, char src_peg, char aux_peg, char dest_peg) {
        if (num_of_disks == 1) {
            printf("Move disk 1 from peg %c to peg %c\n", src_peg, dest_peg);
            return;
        }

        solve_tower_of_hanoi(num_of_disks - 1, src_peg, dest_peg, aux_peg);
        printf("Move disk %d from peg %c to peg %c\n", num_of_disks, src_peg, dest_peg);
        solve_tower_of_hanoi(num_of_disks - 1, aux_peg, src_peg, dest_peg);
    }

    // Call the recursive function to solve the problem
    solve_tower_of_hanoi(num_of_disks, 'A', 'B', 'C');

    printf("\nCongratulations! The problem has been solved!\n");

    return 0;
}