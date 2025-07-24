//FormAI DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>

void brave(int num) {
    if (num == 0) {
        printf("You are brave!");
        return;
    }
    printf("You are still brave!\n");
    brave(num - 1);
}

int main() {
    int i = 10;
    brave(i);
    return 0;
}