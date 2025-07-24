//FormAI DATASET v1.0 Category: Recursive ; Style: random
#include <stdio.h>

int recursiveFunction(int num){
    if(num < 0){
        printf("Invalid number input! Please enter a positive number.\n");
        return -1;
    }
    else if(num == 0){
        return 1;
    }
    else{
        return num * recursiveFunction(num - 1);
    }
}

int main(){
    int num;
    printf("Welcome to the random recursive program!\nPlease enter a positive integer: ");
    scanf("%d", &num);
    printf("The factorial of %d is %d.\n", num, recursiveFunction(num));
    return 0;
}