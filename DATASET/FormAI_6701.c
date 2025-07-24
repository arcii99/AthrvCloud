//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Linus Torvalds
/* 
 * Fibonacci Sequence Visualizer in Linus Torvalds Style
 * Written by <Your Name>
 */
#include <stdio.h>

#define MAX_TERM 50

int main() {
    long prev_term = 0, curr_term = 1;
    int count = 0;

    printf("Fibonacci Sequence Visualizer by <Your Name>\n\n");

    while (count < MAX_TERM) {
        printf("%ld\n", curr_term);
        curr_term += prev_term;
        prev_term = curr_term - prev_term;

        if (curr_term > 1000000) {
            printf("\nYou're making the numbers too big. Calm down, Linus.\n");
            break;
        }

        count++;
    }

    printf("\nDone visualizing the Fibonacci sequence.\n");
    return 0;
}