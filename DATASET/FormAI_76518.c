//FormAI DATASET v1.0 Category: Funny ; Style: brave
#include<stdio.h>

void braveFunction(int num) {
    if(num%2 == 0) {
        printf("Even number detected, but I am not afraid!\n");
    } else {
        printf("Odd number detected, I shall conquer it!\n");
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(num < 0) {
        printf("Negative number detected, fear not I shall handle it perfectly!\n");
    } else {
        braveFunction(num);
    }

    printf("Now, let us calculate some factorials! Give me a number to work with: ");
    scanf("%d", &num);

    int fact = 1;
    for(int i = 1; i <= num; i++) {
        fact *= i;
    }
    printf("The factorial of %d is %d. Tremble before my programming skills!\n", num, fact);

    printf("As a final challenge, I shall demonstrate a recursive function. Enter a number: ");
    scanf("%d", &num);
    int result = recursiveFunction(num);
    printf("The result is %d. Behold my coding prowess!\n", result);

    return 0;
}

int recursiveFunction(int num) {
    if(num <= 0) {
        return 1;
    } else {
        return num * recursiveFunction(num - 1);
    }
}