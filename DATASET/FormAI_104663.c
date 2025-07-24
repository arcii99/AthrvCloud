//FormAI DATASET v1.0 Category: Funny ; Style: satisfied
#include <stdio.h>

int main() {
    printf("Hello! I am finally writing my own unique C program!\n");
    printf("It feels so good to finally accomplish this task!\n");

    // Let's declare some variables
    int myNum = 20;
    float myFloat = 3.14;
    char myChar = 'R';

    // Let's print them out
    printf("My integer is %d\n", myNum);
    printf("My floating-point number is %.2f\n", myFloat);
    printf("My character is %c\n", myChar);

    // Let's perform some arithmetic operations
    int n1 = 10, n2 = 5;
    printf("%d + %d = %d\n", n1, n2, n1 + n2);
    printf("%d - %d = %d\n", n1, n2, n1 - n2);
    printf("%d * %d = %d\n", n1, n2, n1 * n2);
    printf("%d / %d = %d\n", n1, n2, n1 / n2);

    // Let's create a sample function
    void greet(char name[]) {
        printf("Hello, %s! How are you doing today?\n", name);
    }

    // Let's call the function
    greet("John");

    // Let's create a loop
    int i;
    for (i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }

    // Let's create a switch statement
    int choice = 2;
    switch (choice) {
        case 1:
            printf("You chose option 1!\n");
            break;
        case 2:
            printf("You chose option 2!\n");
            break;
        case 3:
            printf("You chose option 3!\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    printf("Wow, I am loving C programming! This is incredible!\n");

    return 0;
}