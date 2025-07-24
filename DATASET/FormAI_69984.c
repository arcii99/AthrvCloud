//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>

void move_plate(int n, char from, char to, char aux) {
    if(n==1) {
        printf("Move plate 1 from %c to %c\n", from, to);
        return;
    }
    move_plate(n-1, from, aux, to);
    printf("Move plate %d from %c to %c\n", n, from, to);
    move_plate(n-1, aux, to, from);
}

int main() {
    int num_plates = 3;
    move_plate(num_plates, 'A', 'C', 'B');
    return 0;
}

// Welcome to the Tower of Hanoi
// In this unique problem, we will test your programming talent
// Let's see if you can solve this!

// The Tower of Hanoi is a classic problem in computer science
// In this problem, we have three poles and a number of plates
// The plates are stacked on one pole in decreasing order of size
// The objective of the problem is to move the entire stack to another pole
// We can only move one plate at a time and we cannot place a larger plate on top of a smaller plate

// In this program, we will be solving the Tower of Hanoi problem using recursion
// The function move_plate takes in three parameters: 
// n - the number of plates to be moved
// from - the pole on which the plates are currently stacked
// to - the pole to which the plates need to be moved
// aux - the auxiliary pole which can be used to move the plates

// The main function sets the number of plates to be 3 and calls the move_plate function
// The move_plate function is then called recursively until all the plates have been moved to the destination pole

// Let's run the program and see the result!