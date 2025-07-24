//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: creative
#include<stdio.h>
#include<stdlib.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
    if (n == 1) 
    { 
        printf("\nFirst disk has been moved from rod %c to rod %c", from_rod, to_rod); 
        return; 
    } 
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod); 
    printf("\n%dth disk has been moved from rod %c to rod %c", n, from_rod, to_rod); 
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
} 

int main() 
{ 
    int n = 0; 
    printf("Enter the number of disks: "); 
    scanf("%d",&n); 
    
    if(n <= 0)
    {
        printf("Number of disks should be greater than 0.");
        exit(0);
    }

    printf("\n\nTower of Hanoi Solution for %d disks:\n\n", n); 
    towerOfHanoi(n, 'A', 'C', 'B'); 
    printf("\n\nEnd of Tower of Hanoi Solution"); 
    return 0; 
}