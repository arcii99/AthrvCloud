//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>

// implementation of Tower of Hanoi problem 
void TowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
    if (n==1) // recursive base case
    { 
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); // print the move
        return; 
    } 
    TowerOfHanoi(n-1, from_rod, aux_rod, to_rod); // recursive call to move n-1 disks from source to auxiliary rod
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); // print the move
    TowerOfHanoi(n-1, aux_rod, to_rod, from_rod); // recursive call to move n-1 disks from auxiliary rod to destination rod
} 

int main() 
{ 
    int n = 4; // number of disks    
    printf("\nSolving Tower of Hanoi problem with %d disks", n); 
    TowerOfHanoi(n, 'A', 'C', 'B'); // call TowerOfHanoi function, starting with source rod A, destination rod C and auxiliary rod B
    
    return 0; 
}