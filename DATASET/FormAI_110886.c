//FormAI DATASET v1.0 Category: Error handling ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

void divide(int num1, int num2){
    if(num2 == 0){
        perror("Division by zero error!\n");
        exit(EXIT_FAILURE);
    }
    else{
        printf("%d / %d = %d\n", num1, num2, (num1/num2));
    }
}

int main(){
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    divide(num1, num2);
    return 0;
}