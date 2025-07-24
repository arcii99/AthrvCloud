//FormAI DATASET v1.0 Category: Math exercise ; Style: shocked
#include<stdio.h>

int factorial(int num){
    if(num == 0){
        return 1;
    }
    else{
        return num * factorial(num - 1);
    }
}

int main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int result = factorial(number);
    printf("Factorial of %d is %d\n", number, result);
    return 0;
}