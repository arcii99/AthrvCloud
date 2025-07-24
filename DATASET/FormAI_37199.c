//FormAI DATASET v1.0 Category: Error handling ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    if(num2 == 0) {
        printf("Error: Cannot divide by zero!");
        exit(0);
    }
    int result = num1 / num2;
    printf("%d / %d = %d", num1, num2, result);
    return 0;
}