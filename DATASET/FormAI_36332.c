//FormAI DATASET v1.0 Category: Recursive ; Style: random
#include <stdio.h>

int factorial(int n){
    if(n == 0) { 
        return 1; 
    }
    return n * factorial(n-1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if(num < 0) {
        printf("Negative numbers are not allowed.\n");
    } else if(num > 12){
        printf("Number too large. Please enter a number between 0 and 12.\n");
    } else {
        printf("The factorial of %d is %d\n", num, factorial(num));
    }
    return 0;
}