//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    int n, a = 0, b = 1, next;
    printf("O Romeo, please enter the number of terms you desire to see in the Fibonacci sequence: ");
    scanf("%d", &n);
    printf("Ah! There is the light!\n");
    printf("The Fibonacci sequence with %d terms is:\n", n);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d, ah, me, the first term will be %d\n", i+1, a);
        } else if (i == 1) {
            printf("%d, the second term shall be %d, my Juliet\n", i+1, b);
        } else {
            next = a + b;
            a = b;
            b = next;
            printf("%d, for the %dth term, my love, it is %d\n", i+1, i+1, next);
        }
    }
    printf("Adieu, my sweetheart\n");
    return 0;
}