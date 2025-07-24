//FormAI DATASET v1.0 Category: Arithmetic ; Style: relaxed
#include<stdio.h>

//Function to find the sum of the digits in a given number
int sum_of_digits(int number) {
    int sum = 0;
    while(number>0) {
        sum += number%10;  //adds the last digit of number to sum
        number = number/10;  //discards the last digit of number
    }
    return sum;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    //Function call to find the sum of digits in the given number
    int sum = sum_of_digits(num);

    printf("The sum of digits in %d is: %d\n", num, sum);

    //Performing some arithmetic operations on the sum
    int result = 2*sum + 5*(sum/3) - 1;

    printf("After performing some arithmetic operations, the result is: %d\n", result);

    return 0;
}