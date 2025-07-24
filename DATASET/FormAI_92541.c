//FormAI DATASET v1.0 Category: Error handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>

void divide(int a, int b){
    if(b==0){
        //Throw the Divide by Zero error
        printf("Error: Cannot divide by zero!\n");
        //Exit the program with error code 1
        exit(1);
    }
    else{
        //Perform the division
        int result = a/b;
        printf("The result of %d / %d is %d\n", a, b, result);
    }
}

int main(){
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    //Call the divide function
    divide(num1, num2);

    //If the program reaches this point, then it has executed successfully
    printf("Program executed successfully.\n");
    
    return 0;
}