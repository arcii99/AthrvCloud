//FormAI DATASET v1.0 Category: Recursive ; Style: immersive
#include <stdio.h>

void recursiveCountdown(int n) {
    // base case
    if (n == 0) {
        printf("Blastoff!\n");
        return;
    } else {
        printf("%d\n", n);
        recursiveCountdown(n-1);
    }
}

int main() {
    int countdownFrom;

    printf("Please enter a number to countdown from: ");
    scanf("%d", &countdownFrom);

    printf("Counting down...\n");

    recursiveCountdown(countdownFrom);

    return 0;
}