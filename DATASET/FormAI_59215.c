//FormAI DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a>b) {
        if(a>c)
            printf("%d is the largest number.", a);
        else
            printf("%d is the largest number.", c);
    }
    else {
        if(b>c)
            printf("%d is the largest number.", b);
        else
            printf("%d is the largest number.", c);
    }

    printf("\n");

    int sum = a + b + c;
    int product = a * b * c;

    printf("The sum of the three numbers is: %d\n", sum);
    printf("The product of the three numbers is: %d\n", product);

    int remainder1 = a%b;
    int remainder2 = b%c;
    int remainder3 = c%a;

    printf("The remainder when %d is divided by %d is: %d\n", a, b, remainder1);
    printf("The remainder when %d is divided by %d is: %d\n", b, c, remainder2);
    printf("The remainder when %d is divided by %d is: %d\n", c, a, remainder3);

    return 0;
}