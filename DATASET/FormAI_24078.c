//FormAI DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (num <= 0) {
        printf("Error. Number must be positive.");
        return 1;
    }
    
    for (int i = 1; i <= num; i++) {
        sum += i;
    }
    
    printf("The sum of the numbers from 1 to %d is %d.\n", num, sum);

    return 0;
}