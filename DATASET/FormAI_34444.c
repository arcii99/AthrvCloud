//FormAI DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Poetry in Code
int main() {
    int num1, num2;
    printf("Oh arithmetic, how poetic your ways,\n");
    printf("With numbers and symbols that dance and sway.\n");
    printf("Love and admiration fills my heart,\n");
    printf("As I write code to show how we never part.\n\n");

    printf("Please enter your first number: ");
    scanf("%d", &num1);
    printf("Ah, %d, how wonderfully divine,\n", num1);
    printf("Now tell me your second number, so we may intertwine.\n");
    scanf("%d", &num2);
    printf("%d, another beautiful number to be,\n", num2);
    printf("Together they'll dance to our arithmetic symphony.\n\n");

    int sum = num1 + num2;
    printf("With addition we are one,\n");
    printf("Our sum is %d, truly second to none.\n\n", sum);

    int diff = num1 - num2;
    printf("Subtraction takes us apart,\n");
    printf("Our difference is %d, but still close to my heart.\n\n", abs(diff));

    int prod = num1 * num2;
    printf("Multiplication brings us closer still,\n");
    printf("Our product is %d, a perfect Chill.\n\n", prod);

    if (num2 == 0) {
        printf("Division is a tricky art,\n");
        printf("But we cannot divide by zero, we must part.\n\n");
        exit(0);
    } 

    float quo = (float) num1 / num2;
    printf("Division, oh division, how complex your embrace,\n");
    printf("Our quotient is %.2f, a value that can't be replaced.\n\n", quo);

    int rem = num1 % num2;
    printf("Modulus, oh modulus, how you bring balance to life,\n");
    printf("Our remainder is %d, without you, we'd have strife.\n", rem);

    return 0;
}