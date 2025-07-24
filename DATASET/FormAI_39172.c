//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void towerOfHanoi(int n, char from_rod[], char to_rod[], char aux_rod[]) {
    
    // If only 1 disk is present then simply move it from source to destination rod
    if (n == 1) {
        printf("Move disk 1 from %s to %s\n", from_rod, to_rod);
        return;
    }
    
    // Recursive call to move (n-1) disk from source to auxiliary rod
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    
    // Moving nth disk from source to destination rod
    printf("Move disk %d from %s to %s\n", n, from_rod, to_rod);
    
    // Recursive call to move (n-1) disk from auxiliary to destination rod
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    
    int n;
    char sourceRod[10] = "Source";
    char auxiliaryRod[10] = "Auxiliary";
    char destinationRod[10] = "Destination";
    
    printf("Enter the number of disks in the tower:\n");
    scanf("%d", &n);
    
    printf("The steps to solve the Tower of Hanoi problem are:\n");
    towerOfHanoi(n, sourceRod, destinationRod, auxiliaryRod);
    
    return 0;
}