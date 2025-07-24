//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: enthusiastic
#include <stdio.h>

// A function to solve Tower of Hanoi problem 
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
        return; 
    } 
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod); 
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
} 

int main() 
{ 
    int n = 4; // Number of disks 
    printf("*********************************************\n");
    printf("*          Welcome to Tower of Hanoi         *\n");
    printf("*********************************************\n");
    printf("*          Let's go and solve this!          *\n");
    printf("*********************************************\n");
    printf("\n");
    printf("Rules:\n");
    printf("1. Only one disk to be moved at a time.\n");
    printf("2. Only the top disk of a stack can be moved.\n");
    printf("3. A disk can only be placed on top of a larger disk or an empty rod.\n");
    printf("\n");

    // Function call
    towerOfHanoi(n, 'A', 'C', 'B'); 
    printf("\n");
    printf("*********************************************\n");
    printf("*               Job Done!                    *\n");
    printf("*********************************************\n");
    return 0; 
}