//FormAI DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>

int main() {
    int num1, num2, sum;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    sum = num1 + num2;
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    
    int i;
    printf("Enter a number to print its multiplication table: ");
    scanf("%d", &i);
    printf("Multiplication table of %d:\n", i);
    for (int j = 1; j <= 10; j++) {
        printf("%d x %d = %d\n", i, j, i*j);
    }
    
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements of array:\n", n);
    for (int k = 0; k < n; k++) {
        scanf("%d", &arr[k]);
    }
    printf("Array elements are: ");
    for (int l = 0; l < n; l++) {
        printf("%d ", arr[l]);
    }
    printf("\n");
    
    char string1[50], string2[50];
    printf("Enter a string: ");
    scanf("%s", string1);
    printf("Enter another string: ");
    scanf("%s", string2);
    printf("Concatenated string: %s%s\n", string1, string2);
    
    return 0;
}