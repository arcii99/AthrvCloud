//FormAI DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>

int main() {
    int num1, num2, total;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    total = (num1 + num2) * 10;

    printf("The total of %d and %d multiplied by 10 is %d.", num1, num2, total);

    if(total > 1000) {
        printf("Wow! That's a big number!");
    }
    else {
        printf("That's not too bad!");
    }

    return 0;
}