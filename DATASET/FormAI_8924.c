//FormAI DATASET v1.0 Category: Arithmetic ; Style: immersive
#include<stdio.h>

int main(){
    printf("Welcome to the immersive world of arithmetic calculations! \n");
    printf("Please input two numbers to perform operations on: \n");

    // Taking user input
    int a, b;
    scanf("%d%d", &a, &b);
    
    printf("\nGreat! Now let's dive into some basic arithmetic operations. \n");
    printf("1. Addition \n");
    printf("%d + %d = %d \n", a, b, a+b);
    
    printf("2. Subtraction \n");
    printf("%d - %d = %d \n", a, b, a-b);
    
    printf("3. Multiplication \n");
    printf("%d x %d = %d \n", a, b, a*b);
    
    printf("4. Division \n");
    if(b == 0){
        printf("Oops! Division by zero is undefined! \n");
    }
    else{
        printf("%d / %d = %.2f \n", a, b, (float)a/b);
    }
    
    printf("\nNow, let's have some fun with modulus operator \n");
    printf("5. Modulus Operator \n");
    printf("%d %% %d = %d \n", a, b, a%b);
    
    printf("\nAlright! Let's move on to some advanced arithmetic operatons. \n");
    printf("6. Increment Operator \n");
    printf(" ++%d = %d \n", a, ++a);
    
    printf("7. Decrement Operator \n");
    printf(" --%d = %d \n", b, --b);
    
    printf("\nFinally, let's play with some ternary operators. \n");
    int result = (a > b) ? a : b;
    printf("8. Ternary Operator \n");
    printf("%d is greater between %d and %d \n", result, a, b);

    return 0;
}