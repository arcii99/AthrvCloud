//FormAI DATASET v1.0 Category: Binary Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num, binaryNum[32], i = 0, j;
 
    printf("Enter an integer: ");
    scanf("%d", &num);
 
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
 
    printf("Binary conversion of entered integer is: ");
    for (j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
 
    return 0;
}