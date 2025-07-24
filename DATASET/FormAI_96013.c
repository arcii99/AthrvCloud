//FormAI DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator with current time
    int x = rand() % 10; // generate a random number between 0 and 9
    int y = rand() % 10; // generate another random number between 0 and 9
    int z; 

    if (x == y) { // check if x and y are equal
        perror("Error! x and y cannot be equal."); // print the error message and terminate the program
        exit(1);
    }

    if (x > y) { // check if x is greater than y
        z = x / y; // divide x by y
    } else {
        z = y / x; // divide y by x
    }

    printf("z = %d\n", z); // print the value of z
    return 0;
}