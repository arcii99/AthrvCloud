//FormAI DATASET v1.0 Category: Recursive ; Style: shocked
#include <stdio.h>

void recursiveCountdown(int n) {
    if(n == 0) {
        printf("Blast off!");
    } else {
        printf("%d... ", n);
        recursiveCountdown(n-1);
    }
}

int main() {
    int n;

    printf("Enter a number to countdown from: ");
    scanf("%d", &n);

    printf("Counting down from %d...\n", n);
    recursiveCountdown(n);

    return 0;
}