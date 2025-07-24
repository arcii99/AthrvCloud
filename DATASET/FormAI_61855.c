//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: inquisitive
#include<stdio.h> 
#include<stdlib.h> 

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
    int n;
    printf("Welcome to the Tower of Hanoi problem.\nEnter the number of disks: ");
    scanf("%d", &n);
    printf("The solution for Tower of Hanoi with %d disks is as follows:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');  
    return 0; 
}