//FormAI DATASET v1.0 Category: Recursive ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int recursive(int n, int previous) {
    if (n < 1) {
        printf("Invalid input. Terminating program.\n");
        exit(0);
    }

    int rand_num = rand() % 100;

    if (rand_num % 2 == 0 && rand_num != previous) {
        printf("Number: %d\n", rand_num);
        recursive(n-1, rand_num);
    } else {
        printf("Paranoid signature detected. Terminating program.\n");
        exit(0);
    }
}

int main() {
    int num_iterations = 10;
    int starting_num = rand() % 100;

    printf("Starting number: %d\n", starting_num);
    recursive(num_iterations-1, starting_num);

    return 0;
}