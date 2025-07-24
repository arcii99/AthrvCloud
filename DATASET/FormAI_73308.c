//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ephemeral
/* 
"Help me Obi-Wan Kenobi, you're my only hope."
- Princess Leia Organa (Star Wars: A New Hope)
*/

#include <stdio.h>

// Function prototypes
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod);

int main() {
    int num_disks = 5;
    
    printf("Welcome to the Tower of Hanoi problem, Jedi master!\n");
    printf("We are facing a problem of moving %d disks from rod A to rod C,\n", num_disks);
    printf("using rod B as an auxiliary rod. Are you ready?\n\n");
    
    tower_of_hanoi(num_disks, 'A', 'C', 'B');
    
    printf("\nCongratulations, you have successfully completed the mission! May the force be with you.\n");
    
    return 0;
}

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        return;
    }
    
    tower_of_hanoi(n-1, from_rod, aux_rod, to_rod);
    
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    
    tower_of_hanoi(n-1, aux_rod, to_rod, from_rod);
}