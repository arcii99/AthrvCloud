//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the move
void move(int n, char source, char destination, char auxiliary) {
    printf("Move disk %d from %c to %c\n", n, source, destination);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        move(n, source, destination, auxiliary);
        return;
    }
    tower_of_hanoi(n - 1, source, auxiliary, destination);
    move(n, source, destination, auxiliary);
    tower_of_hanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    char source = 'A';
    char destination = 'C';
    char auxiliary = 'B';

    printf("Enter the number of disks:\n");
    scanf("%d", &n);

    if (n < 1) {
        printf("Invalid input! Please enter a positive number.\n");
        return 1;
    }
    
    printf("The Tower of Hanoi problem with %d disks can be solved with the following moves:\n", n);
    tower_of_hanoi(n, source, destination, auxiliary);

    return 0;
}