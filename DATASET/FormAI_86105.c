//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
// defining the function for tower of Hanoi problem
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
int main(){
    int n;
    // asking for the number of discs
    printf("Enter the number of discs in tower of Hanoi problem: ");
    scanf("%d", &n);
    // Checking if number of discs is less than or equal to 0 or not.
    if(n <= 0){
        printf("Invalid input\n");
        exit(0);
    }
    printf("\nThe steps to solve the Tower of Hanoi problem are as follows: ");
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}