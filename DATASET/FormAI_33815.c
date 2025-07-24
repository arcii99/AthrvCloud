//FormAI DATASET v1.0 Category: Recursive ; Style: happy
#include <stdio.h>

// A happy recursive function to print numbers in ascending order! :)
void printNums(int start, int end) {

    // Base case: when start exceeds end, stop calling the function
    if (start > end) {
        printf("Yay, we're done printing!\n");
        return;
    }

    // Print the current number and call the function again with next number
    printf("%d\n", start);
    printNums(start+1, end);
}

int main() {

    // Let's print some numbers from 1 to 10!
    printf("Let's get happy and print some numbers!\n");
    printNums(1, 10);

    return 0;
}