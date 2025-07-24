//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next;

    printf("O Romeo, O Romeo! We shall create a Fibonacci sequence unto thee.\n");
    printf("How many terms shall we generate for thee, fair Juliet? ");

    scanf("%d", &n);

    printf("Very well, my dear Juliet. Let us proceed.\n");

    for (int i = 0; i < n; i++) {
        if (i == 0 || i == 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("Term %d: %d\n", i+1, next);
    }

    printf("Thus ends our Fibonacci sequence, fair Juliet.\n");

    return 0;
}