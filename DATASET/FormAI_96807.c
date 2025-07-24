//FormAI DATASET v1.0 Category: Recursive ; Style: shocked
#include <stdio.h>

void countDown(int num);

int main() {
    int n = 10;

    printf("Get ready to be shocked!\n");
    printf("Counting down from %d...\n", n);

    countDown(n);

    printf("Blast off!\n");

    return 0;
}

void countDown(int num) {
    if (num == 0) {
        return;
    }

    printf("%d...\n", num);
    countDown(num - 1);
}