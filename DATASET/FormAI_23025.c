//FormAI DATASET v1.0 Category: Recursive ; Style: bold
#include <stdio.h>

void recursiveFunction(int n) {
    if(n == 0) {
        return;
    }
    else {
        printf("%d\n", n);
        recursiveFunction(n-1);
        printf("%d\n", n);
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Recursive output:\n");
    recursiveFunction(num);

    return 0;
}