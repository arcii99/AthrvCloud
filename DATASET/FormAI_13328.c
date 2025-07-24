//FormAI DATASET v1.0 Category: Scientific ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num, sum = 0, digits = 0, temp, i;

    printf("Enter the number: ");
    scanf("%d", &num);

    temp = num;

    while(temp != 0) {
        digits++;
        temp = temp / 10;
    }

    temp = num;

    for(i = digits; i >= 1; i--) {
        int pow_result = pow(10, i-1);
        int digit = temp / pow_result;
        sum = sum + pow(digit, digits);
        temp = temp % pow_result;
    }

    if(sum == num) {
        printf("%d is an Armstrong number!", num);
    } else {
        printf("%d is not an Armstrong number.", num);
    }

    return 0;
}