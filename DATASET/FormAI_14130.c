//FormAI DATASET v1.0 Category: Educational ; Style: inquisitive
#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if(num < 0) {
        printf("The number is negative.\n");
    } else if(num == 0) {
        printf("The number is zero.\n");
    } else {
        printf("The number is positive.\n");
    }
    
    int i, j, n;
    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &n);
    
    for(i=1; i<=n; i++) {
        for(j=1; j<=i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 0;
    
    for(i=0; i<5; i++) {
        sum += arr[i];
    }
    
    printf("The sum of the array is: %d\n", sum);
    
    int factorial = 1;
    
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    
    for(i=1; i<=num; i++) {
        factorial *= i;
    }
    
    printf("The factorial of %d is: %d\n", num, factorial);
    
    return 0;
}