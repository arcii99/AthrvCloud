//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include<stdio.h>
#include<stdlib.h>

void tower_of_hanoi(int n, char source, char dest, char aux) {

    // Base Case
    if(n==1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }

    // Recursion
    tower_of_hanoi(n-1, source, aux, dest);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    tower_of_hanoi(n-1, aux, dest, source);

}

int main() {

    int n;
    char source='A', dest='C', aux='B';

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Validation
    if(n<1) {
        printf("Number of disks cannot be less than 1\n");
        return 0;
    }

    printf("The sequence of moves involved in the Tower of Hanoi is:\n");
    tower_of_hanoi(n, source, dest, aux);
    
    return 0;
}