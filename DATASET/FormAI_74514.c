//FormAI DATASET v1.0 Category: Recursive ; Style: shocked
#include <stdio.h>

void recursive(int n) {
    if(n == 0) {
        printf("The End!");
        return;
    }
    printf("%d\t", n);
    recursive(n - 1);
}

int main() {
    int number = 10;
    recursive(number);
    return 0;
}