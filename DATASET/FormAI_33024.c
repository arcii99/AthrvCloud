//FormAI DATASET v1.0 Category: Educational ; Style: curious
#include <stdio.h>

int main() {
    int num1, num2, sum; // declare variables
    printf("Enter two numbers: "); // prompt user
    scanf("%d%d", &num1, &num2); // read input from user
    sum = num1 + num2; // add the numbers
    printf("\nThe sum of %d and %d is %d.\n", num1, num2, sum); // display the result
    if(sum%2==0){ // check if sum is even
        printf("The sum is even.\n");
    }
    else{ // if sum is odd
        printf("The sum is odd.\n");
    }
    int i;
    for(i=1;i<=sum;i++){ // print the numbers from 1 to the sum
        printf("%d ",i);
    }
    printf("\n");
    int j,sum2 = 0;
    for(j=1;j<=num1;j++){ // calculate the factorial of num1
        sum2 = sum2*j;
    }
    printf("The factorial of %d is %d.\n",num1,sum2); // display the factorial
    int k, num3 = 0;
    printf("Enter a number: ");
    scanf("%d",&num3); // read input from user
    for(k=1;k<=num3;k++){ // check if the number is prime
        if(num3%k==0){
            sum2++;
        }
    }
    if(sum2==2){
        printf("%d is a prime number.\n",num3);
    }
    else{
        printf("%d is not a prime number.\n",num3);
    }
    return 0; // indicate successful program execution
}