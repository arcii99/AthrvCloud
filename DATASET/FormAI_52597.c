//FormAI DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include<stdio.h>
#include<math.h>

int main(){
    int a, b, c, d;
    printf("Welcome to the Imaginative Arithmetic Program\n");
    printf("Please enter an integer value for variable a: ");
    scanf("%d", &a);
    printf("Please enter an integer value for variable b: ");
    scanf("%d", &b);
    printf("Please enter an integer value for variable c: ");
    scanf("%d", &c);

    // Calculate the imaginary part of a complex number
    d = sqrt(-1);
    printf("\nThe value of the square root of -1 is: %di\n", d);

    // Calculate the sum of the three integer variables
    int sum = a + b + c;
    printf("The sum of the three variables is: %d\n", sum);

    // Calculate the factorial of c
    int factorial = 1;
    for(int i = 1; i <= c; i++){
        factorial *= i;
    }
    printf("The factorial of %d is: %d\n", c, factorial);

    // Calculate the remainder of a/c
    int remainder = a % c;
    printf("The remainder of %d divided by %d is: %d\n", a, c, remainder);

    // Calculate the square of b
    int square = pow(b, 2);
    printf("The square of %d is: %d\n", b, square);

    // Calculate the absolute value of a-b
    int absdiff = abs(a-b);
    printf("The absolute value of %d minus %d is: %d\n", a, b, absdiff);

    // Display a cool message
    printf("\nCongratulations! You have successfully completed the Imaginative Arithmetic Program.\n");
    printf("We hope you enjoyed this unique program and learned something new about C programming.\n");

    return 0;
}