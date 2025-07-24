//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

void countDown(int num) {
    if(num == 0) {
        printf("Countdown complete!\n");
        return;
    }
    printf("%d\n", num);
    countDown(num-1);
}

int main() {
    printf("Starting countdown...\n");
    countDown(10);
    printf("All done!\n");
    return 0;
}