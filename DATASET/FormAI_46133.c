//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination);

int main(){
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", &n);

    // Calling the function to solve the Tower of Hanoi problem
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}

void towerOfHanoi(int n, char source, char auxiliary, char destination){
    if(n == 1){
        printf("\nMove the disk 1 from %c to %c", source, destination);
        return;
    }
    towerOfHanoi(n-1, source, destination, auxiliary);
    printf("\nMove the disk %d from %c to %c", n, source, destination);
    towerOfHanoi(n-1, auxiliary, source, destination);
}