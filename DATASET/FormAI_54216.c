//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    if(num2 == 0) {
        printf("Error: Cannot divide by zero!\n");
        exit(0); // terminate program
    }

    int result = num1 / num2;
    printf("%d divided by %d is %d\n", num1, num2, result);

    return 0;
}