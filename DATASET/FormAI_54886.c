//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include<stdio.h>

//Function to move blocks from one tower to another
void move(int n, char source_tower, char destination_tower, char auxiliary_tower) 
{ 
    if (n == 1) //If only one block is there, move it directly to destination tower
    { 
        printf("Move block 1 from %c to %c\n", source_tower, destination_tower); 
        return; 
    } 
    
    move(n-1, source_tower, auxiliary_tower, destination_tower); //Move (n-1) blocks from source tower to auxiliary tower
    
    printf("Move block %d from %c to %c\n", n, source_tower, destination_tower); //Move the last (nth) block to destination tower
    
    move(n-1, auxiliary_tower, destination_tower, source_tower); //Move (n-1) blocks from auxiliary tower to destination tower
} 

int main() 
{ 
    int n;
    printf("Enter the number of blocks: ");
    scanf("%d", &n);
    
    move(n, 'A', 'C', 'B');  // A, B and C are the tower names 
    return 0; 
}