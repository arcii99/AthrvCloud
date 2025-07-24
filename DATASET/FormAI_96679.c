//FormAI DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
#include <stdio.h>

void printNum(int n) {
    printf("%d\n", n);
    if (n <= 0) {
        return;
    }
    printNum(n-1);
}

int main() {
    int num = 10;
    printNum(num);
    return 0;
}