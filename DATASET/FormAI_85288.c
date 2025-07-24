//FormAI DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>

/* function to calculate the factorial of a given number */
int factorial(int num) {
    if (num == 0) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}

/* function to calculate the sum of the factorial of each digit in a given number */
int digitFactorialSum(int num) {
    int sum = 0;
    while (num) {
        sum += factorial(num % 10);
        num /= 10;
    }
    return sum;
}

/* function to check if a given number is a strong number */
int isStrong(int num) {
    return num == digitFactorialSum(num);
}

/* function to display all the strong numbers between two given numbers */
void displayStrongNumbers(int start, int end) {
    printf("Strong numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        if (isStrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

/* main function */
int main() {
    int start, end;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);
    displayStrongNumbers(start, end);
    return 0;
}