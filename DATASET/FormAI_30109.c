//FormAI DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

float divide(float num1, float num2){
    if(num2 == 0){
        printf("Error: Cannot divide by zero");
        exit(1);
    }
    return num1 / num2;
}

int main(){
    float num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    result = divide(num1, num2);
    printf("The result is: %f", result);
    return 0;
}