//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

void printGratitude(int num) {
    // base case
    if (num == 0) {
        printf("Thank you for everything!\n");
        return;
    }

    // recursive case
    printf("Thank you %d times!\n", num);
    printGratitude(num - 1);
}

int main() {
    int num = 5;

    // show gratitude recursively
    printf("Showing gratitude recursively:\n\n");
    printGratitude(num);

    return 0;
}