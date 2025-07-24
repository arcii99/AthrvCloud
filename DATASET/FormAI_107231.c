//FormAI DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>

void apocalypse(int n) {
    if(n == 0) {
        printf("The end of the world is near!\n");
    } else {
        printf("Year %d has passed.\n", n);
        apocalypse(n-1);
    }
}

int main() {
    apocalypse(50);
    return 0;
}