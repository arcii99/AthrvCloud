//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void printGratefulness(int count) {
    if (count == 0) {
        return; // recursion base condition
    }

    printf("I am grateful for this code snippet, which helps me learn new things.\n");
    printGratefulness(count - 1); // recursive call
}

int main() {
    int count = 10;

    printf("This is a Recursive program to show my gratitude towards programming.\n");
    printf("I want to express my gratitude %d times.\n", count);

    printGratefulness(count);

    printf("Thank you for helping me become a better programmer!\n");

    return EXIT_SUCCESS;
}