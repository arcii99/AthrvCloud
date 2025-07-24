//FormAI DATASET v1.0 Category: Scientific ; Style: happy
#include <stdio.h>
#include <math.h>

int main() {
    printf("Hey there, let's do some cool scientific stuff today!\n\n");
    printf("Let's start with finding the factorial of a number.\n");
    
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    int factorial = 1;
    for(int i = 1; i <= num; i++) {
        factorial *= i;
    }
    
    printf("The factorial of %d is %d.\n\n", num, factorial);
    
    printf("Now, let's find the square root of a number.\n");
    
    float x;
    printf("Enter a positive number: ");
    scanf("%f", &x);
    
    float sqrt_num = sqrt(x);
    
    printf("The square root of %.2f is %.2f.\n\n", x, sqrt_num);
    
    printf("Finally, let's calculate the value of pi using Leibniz formula.\n");
    
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    double pi = 0;
    for(int i = 0; i < n; i++) {
        pi += (pow(-1, i) / (2 * i + 1));
    }
    pi *= 4;
    
    printf("The value of pi using Leibniz formula with n = %d is %.10f.\n\n", n, pi);
    
    printf("Wow, that was fun! Come back again for some more cool scientific stuff!\n");
    
    return 0;
}