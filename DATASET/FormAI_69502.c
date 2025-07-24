//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: innovative
#include<stdio.h> 

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
    if (n == 1) 
    { 
        printf("\nMove disk 1 from rod %c to rod %c", from_rod, to_rod); 
        return; 
    } 
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod); 
    printf("\nMove disk %d from rod %c to rod %c", n, from_rod, to_rod); 
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
} 

int main() 
{ 
    int n;
    printf("Welcome to the C Tower of Hanoi Problem Example Program!\n\n");
    printf("Please enter the number of disks: ");
    scanf("%d",&n);
    printf("\nThe sequence of moves involved in the Tower of Hanoi problem with %d disks is:\n", n); 
    towerOfHanoi(n, 'A', 'C', 'B'); 
    printf("\n\nThank you for using our program!\n");
    return 0; 
}