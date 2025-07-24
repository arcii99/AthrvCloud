//FormAI DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>

void countdown(int n) {
    if (n == 0) {
        printf("BRAVERY ACHIEVED!\n");
    } else {
        printf("%d... ", n);
        countdown(n-1);
    }
}

int main() {
    printf("We are about to embark on a brave journey!\n");
    printf("Get ready to count down to the bravest moment...\n");
    countdown(10);
    return 0;
}