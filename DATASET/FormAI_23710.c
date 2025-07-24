//FormAI DATASET v1.0 Category: Recursive ; Style: standalone
#include <stdio.h>

void recursivePrint(int n) {
    if(n == 0) {
        printf("\n");
        return;
    }
    else {
        printf("%d ", n);
        recursivePrint(n-1);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num >= 0) {
        recursivePrint(num);
    }
    else {
        printf("Error: Entered number is not positive.\n");
    }
    return 0;
}