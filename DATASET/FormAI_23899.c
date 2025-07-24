//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int n, first = 0, second = 1, next, i;

    printf("Love, sweet love, behold the Fibonacci sequence in all its glory!\n\n");

    printf("How many terms of the sequence shall I generate for thee, my love? ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        }
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("My love, behold the %d%s term of the sequence: %d\n", 
               i + 1, 
               (i == 0) ? "st" : (i == 1) ? "nd" : "th",
               next);
    }

    printf("\nMy Juliet, do you not find this sequence most pleasing?\n");

    return 0;
}