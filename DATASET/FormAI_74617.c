//FormAI DATASET v1.0 Category: Funny ; Style: complex
#include <stdio.h>
#include <stdlib.h>

char msg[] = "Hello, world!";

void printChar(char c) {
    printf("%c", c);
}

void printMsg() {
    int i;
    for(i = 0; msg[i] != '\0'; i++) {
        printChar(msg[i]);
    }
}

int* add(int num1, int num2) {
    int* ans = malloc(sizeof(int));
    *ans = num1 + num2;
    return ans;
}

int main() {
    printf("Welcome to my complex program!\n");

    printf("The message is: ");
    printMsg();
    printf("\n");

    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    int* result = add(num1, num2);
    printf("The sum of %d and %d is %d.\n", num1, num2, *result);

    free(result);
    printf("Thanks for using my program!\n");
    return 0;
}