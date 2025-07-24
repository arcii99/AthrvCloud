//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mathematical
/*
Tower of Hanoi Problem: Mathematical Style

In this program, we are going to implement Tower of Hanoi Problem using mathematical formulas.
We will use a recursive approach to solve this problem.
*/

#include <stdio.h>
#include <math.h>

// tower of hanoi function
void tower_of_hanoi(int n, char from, char to, char aux) {
    double moves = pow(2, n) - 1; // calculate total number of moves using formula 2^n - 1
    printf("Total number of moves required to solve Tower of Hanoi problem with n=%d are %.0lf\n", n, moves);
}

// main function
int main() {
    int n = 5; // number of disks
    char from = 'A', to = 'C', aux = 'B';

    tower_of_hanoi(n, from, to, aux);

    return 0;
}