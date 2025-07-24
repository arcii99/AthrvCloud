//FormAI DATASET v1.0 Category: Funny ; Style: calm
#include<stdio.h>
#include<stdlib.h>

int main(){
    int num1, num2;
    printf("Enter two numbers:");
    scanf("%d %d", &num1, &num2);
    int sum = num1 + num2;
    int product = num1 * num2;
    int difference = abs(num1 - num2);
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The product of %d and %d is %d\n", num1, num2, product);
    printf("The absolute difference between %d and %d is %d\n", num1, num2, difference);
    if(num1 > num2){
        printf("%d is greater than %d\n", num1, num2);
    }
    else if(num1 < num2){
        printf("%d is less than %d\n", num1, num2);
    }
    else{
        printf("%d is equal to %d\n", num1, num2);
    }
    for(int i=0; i<num1; i++){
        printf("*");
    }
    printf("\n");
    for(int i=0; i<num2; i++){
        printf("#");
    }
    printf("\n");
    return 0;
}