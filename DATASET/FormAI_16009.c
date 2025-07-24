//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>

void solve_tower_of_hanoi(int numOfDisks, char fromRod, char toRod, char auxRod, int* stepCount){
    if(numOfDisks == 1){
        (*stepCount)++;
        printf("%d. Move disk 1 from rod %c to rod %c\n", *stepCount, fromRod, toRod);
    	return;
    }
    solve_tower_of_hanoi(numOfDisks-1, fromRod, auxRod, toRod, stepCount);
    (*stepCount)++;
    printf("%d. Move disk %d from rod %c to rod %c\n", *stepCount, numOfDisks, fromRod, toRod);  
    solve_tower_of_hanoi(numOfDisks-1, auxRod, toRod, fromRod, stepCount); 
}

int main()
{
    int numOfDisks;
    int stepCount = 0;
    printf("Enter the number of disks: ");
    scanf("%d", &numOfDisks);
    solve_tower_of_hanoi(numOfDisks, 'A', 'C', 'B', &stepCount);
    printf("Number of steps required to solve the problem: %d", stepCount);
    return 0; 
}