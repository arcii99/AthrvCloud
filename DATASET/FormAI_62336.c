//FormAI DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void divide(int num1, int num2){
    if (num2 == 0){
        printf("Error: Division by zero.\n");
        exit(1);
    }
    printf("%d / %d = %d\n", num1, num2, num1/num2);
}

int main(){
    int a, b;
    printf("Enter two integers to divide: ");
    scanf("%d %d", &a, &b);
    divide(a, b);
    printf("End of program.\n");
    return 0;
}