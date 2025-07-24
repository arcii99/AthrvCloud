//FormAI DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int recursive(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * recursive(n-1);
    }
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if(num < 0){
        printf("Input invalid\n");
        exit(0);
    }

    int result = recursive(num);
    printf("%d! = %d\n", num, result);

    return 0;
}