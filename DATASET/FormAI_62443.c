//FormAI DATASET v1.0 Category: Scientific ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, num3;

    printf("Enter three numbers:\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 > num2 && num1 > num3) {
        printf("The largest number is: %d\n", num1);
    }
    else if (num2 > num1 && num2 > num3) {
        printf("The largest number is: %d\n", num2);
    }
    else {
        printf("The largest number is: %d\n", num3);
    }

    return 0;
}