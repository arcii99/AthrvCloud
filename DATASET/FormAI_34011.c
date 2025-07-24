//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>

int tower_of_hanoi(int num_disks, char from_peg, char to_peg, char aux_peg) {
    if (num_disks == 1) {
        printf("\nMove disk 1 from peg %c to peg %c", from_peg, to_peg);
        return 1;
    }

    int moves = 0;
    moves += tower_of_hanoi(num_disks - 1, from_peg, aux_peg, to_peg);
    printf("\nMove disk %d from peg %c to peg %c", num_disks, from_peg, to_peg);
    moves++;
    moves += tower_of_hanoi(num_disks - 1, aux_peg, to_peg, from_peg);

    return moves;
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    int moves = tower_of_hanoi(num_disks, 'A', 'C', 'B');
    printf("\n\nNumber of moves: %d", moves);

    return 0;
}