//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
    if (n == 1) //base condition 
    { 
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod); 
        return; 
    } 
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod); //moving n-1 from source to auxiliary 
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod); //moving nth disk from source to destination 
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod); //moving n-1 disks from auxilary to destination 
} 

int main() 
{ 
    int n;
    printf("\nEnter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B'); //calling function and giving rod names as A, C and B
    return 0; 
}