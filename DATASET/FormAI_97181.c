//FormAI DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void check_input(int num) {
    if(num < 0 || num > 10) {
        fprintf(stderr, "Error: Invalid input!\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int num;

    printf("Please enter a number between 0 and 10: ");
    if(scanf("%d", &num) != 1) {
        perror("Error in input: scanf failed");
        exit(EXIT_FAILURE);
    }

    check_input(num);

    // Perform operations with num

    return 0;
}