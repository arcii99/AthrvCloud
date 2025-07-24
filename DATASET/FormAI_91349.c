//FormAI DATASET v1.0 Category: Error handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int divide(int num1, int num2){

    if(num2 == 0){
        //setting the error code
        errno = EINVAL;
        //returning error value
        return -1;
    }

    //returning normal result
    return num1/num2;
}

int main(){
    int result = 0, num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    //calling the divide function
    result = divide(num1, num2);

    //checking for errors
    if(result == -1){

        //printing error message
        perror("Error Occured: ");
        //printing error code
        printf("Error Code: %d\n", errno);
    } else{
        //printing result
        printf("Result = %d\n", result);
    }

    return 0;
}