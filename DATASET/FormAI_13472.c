//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Claude Shannon
/**
* A simple implementation of Tower of Hanoi problem using C programming language.
* This program demonstrates the famous recursive algorithm that can be used to solve Tower of Hanoi problem, 
* where we need to move a stack of discs from one peg to another peg.
*
* The main idea behind this algorithm is to split problem into sub-problems, 
* solve those sub-problems recursively, and then combine the results to solve the main problem.
* 
* This is an example program demonstrating how to move n discs from a peg called 'A' to another peg called 'C'
* using an intermediate peg called 'B'. 
* 
* This implementation also illustrates the use of an array to keep track of the number of disks on each peg.
*
* Author: Claude Shannon
*/

#include <stdio.h>

// function to move the disc from peg 'from' to peg 'to'
void moveDisc(char from, char to) {
    printf("Move disk from %c to %c\n", from, to);
}

// recursive function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char from, char to, char temp, int disks[]) {
    if (n == 0) {
        return;
    }

    // move n-1 disks from 'from' to 'temp'
    towerOfHanoi(n-1, from, temp, to, disks);
    
    // move the n-th disc from 'from' to 'to'
    moveDisc(from, to);
    
    // update number of disks on respective pegs
    disks[from - 'A']--;
    disks[to - 'A']++;
    
    // move n-1 disks from 'temp' to 'to'
    towerOfHanoi(n-1, temp, to, from, disks);
}

int main(void) {
    // Create an array to store the number of disks on each peg
    int disks[3] = {3, 0, 0}; // there are 3 disks on peg 'A' and none on peg 'B' and 'C'
    
    // Start solving Tower of Hanoi problem
    towerOfHanoi(3, 'A', 'C', 'B', disks);
    
    // Print final status of pegs after the problem is solved
    printf("\nFinal state of pegs:\n");
    printf("Peg A: %d disks\n", disks[0]);
    printf("Peg B: %d disks\n", disks[1]);
    printf("Peg C: %d disks\n", disks[2]);
    
    return 0;
}