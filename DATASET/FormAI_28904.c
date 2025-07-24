//FormAI DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>

void brave(int count) {
    if (count == 0) {
        printf("I am a brave programmer!\n");
    } else {
        printf("I am not afraid of recursion!\n");
        brave(count - 1);
    }
}

int main() {
    int count;
    printf("Enter the number of times to be brave: ");
    scanf("%d", &count);

    brave(count);

    return 0;
}