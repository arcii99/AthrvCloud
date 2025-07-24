//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include<stdio.h>
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {  
    if(n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c", fromRod, toRod);
        return;
    }  
    towerOfHanoi(n-1, fromRod, auxRod, toRod);
    printf("\nMove disk %d from rod %c to rod %c", n, fromRod, toRod);
    towerOfHanoi(n-1, auxRod, toRod, fromRod); 
}
int main() {  
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n); 
    if(n <= 0) {
        printf("Invalid Input!");
        return 0;
    }
    printf("\nThe steps to be followed are:\n");
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}