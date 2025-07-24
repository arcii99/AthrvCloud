//FormAI DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, sum, diff, prod;
    float quotient;

    printf("Enter the first integer: ");
    scanf("%d", &num1);
    printf("Enter the second integer: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quotient = (float)num1 / num2;

    printf("\nSUM of %d and %d is %d", num1, num2, sum);
    printf("\nDIFFERENCE of %d and %d is %d", num1, num2, diff);
    printf("\nPRODUCT of %d and %d is %d", num1, num2, prod);
    printf("\nQUOTIENT of %d and %d is %.2f", num1, num2, quotient);

    int arr1[5] = {2, 4, 6, 8, 10};
    int arr2[5] = {1, 3, 5, 7, 9};
    int arr3[5];

    printf("\n\nElements of array 1: ");
    for(int i=0; i<5; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\nElements of array 2: ");
    for(int i=0; i<5; i++) {
        printf("%d ", arr2[i]);
    }

    printf("\n\nADDING corresponding elements of both arrays\n");
    for(int i=0; i<5; i++) {
        arr3[i] = arr1[i] + arr2[i];
        printf("%d + %d = %d\n", arr1[i], arr2[i], arr3[i]);
    }

    return 0;
}