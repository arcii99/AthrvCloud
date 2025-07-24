//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: excited
#include <stdio.h>

void move_piece(char start_peg, char end_peg) {
    printf("Moving piece from Peg %c to Peg %c\n", start_peg, end_peg);
}

void TowerOfHanoi(int n, char start_peg, char mid_peg, char end_peg) {
    if (n == 1) {
        move_piece(start_peg, end_peg);
        return;
    }
    TowerOfHanoi(n - 1, start_peg, end_peg, mid_peg);
    move_piece(start_peg, end_peg);
    TowerOfHanoi(n - 1, mid_peg, start_peg, end_peg);
}

int main() {
    int num_disks = 3;
    printf("Welcome to the Tower of Hanoi!\n");
    printf("We have %d disks to move from Peg A to Peg C.\n", num_disks);
    TowerOfHanoi(num_disks, 'A', 'B', 'C');
    printf("All disks have been moved to Peg C. Congratulations!\n");
    return 0;
}