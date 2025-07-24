//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: peaceful
#include <stdio.h>

void TowerOfHanoi(int n, char source, char destination, char auxiliary){
    if(n==1){
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    TowerOfHanoi(n-1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    TowerOfHanoi(n-1, auxiliary, destination, source);
}

int main(){
    int n = 4;
    printf("Welcome to the Tower of Hanoi!\n\n");
    printf("Here are the steps to solve for %d disks:\n\n", n);
    TowerOfHanoi(n, 'A', 'C', 'B');
    printf("\nCongratulations! You've successfully completed the Tower of Hanoi!\n");
    return 0;
}