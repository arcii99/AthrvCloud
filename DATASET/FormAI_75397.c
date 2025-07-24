//FormAI DATASET v1.0 Category: Scientific ; Style: brave
#include <stdio.h>

int main() {
    printf("I am a brave C program!\n");
    int a = 5, b = 3;
    int sum = a + b;
    printf("The sum of %d and %d is %d\n", a, b, sum);
    int product = a * b;
    printf("The product of %d and %d is %d\n", a, b, product);
    double quotient = (double) a / b;
    printf("The quotient of %d divided by %d is %.2f\n", a, b, quotient);
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);
    printf("Hello %s, nice to meet you!\n", name);
    int age;
    printf("How old are you? ");
    scanf("%d", &age);
    if (age >= 18) {
        printf("Wow %s, you're an adult!\n", name);
    } else {
        printf("Hey %s, you're still a kid!\n", name);
    }
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    if (num1 > num2) {
        printf("%d is greater than %d\n", num1, num2);
    } else if (num2 > num1) {
        printf("%d is greater than %d\n", num2, num1);
    } else {
        printf("%d and %d are equal\n", num1, num2);
    }
    return 0;
}