//FormAI DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>

int main(){
    int num1, num2;
    printf("Enter two numbers:\n");
    if(scanf("%d %d", &num1, &num2) != 2){
        printf("Oops, invalid input. Please enter two numbers separated by a space.\n");
        return 1;
    }
    
    int result;
    if(num2 == 0){
        printf("Oops, can't divide by zero. Please enter a non-zero number.\n");
        return 1;
    }else{
        result = num1 / num2;
        printf("%d divided by %d equals %d\n", num1, num2, result);
    }
    
    return 0;
}