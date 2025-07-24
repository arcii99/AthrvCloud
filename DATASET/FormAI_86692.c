//FormAI DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num1, num2, result;
    printf("Enter two integers: ");
    if(scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter two integers.\n");
        exit(1);
    }
    if(num2 == 0) {
        printf("Error: division by zero.\n");
        exit(1);
    }
    result = num1 / num2;
    if(result == 0) {
        printf("Error: division resulted in zero.\n");
        exit(1);
    }
    printf("%d divided by %d is %d\n", num1, num2, result);
    return 0;
}