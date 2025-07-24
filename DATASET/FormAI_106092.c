//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: puzzling
#include<stdio.h>

void hanoi(int n, char source, char auxiliary, char destination){
    if(n==1){
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    hanoi(n-1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    hanoi(n-1, auxiliary, source, destination);
}

int main(){
    int n = 4;
    char source = 'A', auxiliary = 'B', destination = 'C';
    printf("TOWER OF HANOI PUZZLE\n\n");
    printf("Number of disks: %d\n", n);
    printf("Initial Tower Configuration:\n");
    for(int i=n; i>=1; i--){
        printf("Disk %d: %c\n", i, source);
    }
    printf("\nSteps to solve the puzzle:\n");
    hanoi(n, source, auxiliary, destination);
    printf("\nFinal Tower Configuration:\n");
    for(int i=n; i>=1; i--){
        printf("Disk %d: %c\n", i, destination);
    }
    return 0;
}