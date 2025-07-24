//FormAI DATASET v1.0 Category: Scientific ; Style: creative
#include<stdio.h>

int main(){
    int num1, num2, sum;

    printf("Enter two numbers separated with a space: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;

    printf("The sum of %d and %d is: %d\n", num1, num2, sum);

    if(sum % 2 == 0){
        printf("%d is an even number.\n", sum);
    }else{
        printf("%d is an odd number.\n", sum);
    }

    int factorial = 1;
    for(int i = 1; i <= num1; i++){
        factorial = factorial * i;
    }

    printf("Factorial of %d is %d\n", num1, factorial);

    printf("The second number in binary is: ");
    int binaryNum[32], i = 0;
    while(num2 > 0){
        binaryNum[i] = num2 % 2;
        num2 = num2/2;
        i++;
    }

    for(int j = i - 1; j >=0; j--){
        printf("%d", binaryNum[j]);
    }
    
    return 0;
}