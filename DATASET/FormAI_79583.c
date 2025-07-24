//FormAI DATASET v1.0 Category: Binary Converter ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

int main() {
    int decimal, binary[100], index = 0, temp;

    // Taking input from user
    printf("Enter the decimal number: ");
    scanf("%d", &decimal);
    temp = decimal;

    // Calculating binary equivalent
    while(temp > 0) {
        binary[index] = temp % 2;
        temp = temp / 2;
        index++;
    }

    // Displaying binary equivalent
    printf("Binary equivalent of %d is: ", decimal);
    for(int i=index-1; i>=0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
    return 0;
}