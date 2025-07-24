//FormAI DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include<stdio.h>

int main(){
    unsigned long long decimal, binary = 0;
    int digit, exponent = 0;
    printf("Enter a decimal number: ");
    scanf("%llu", &decimal);
    while(decimal != 0){
        digit = decimal % 2;
        binary += digit * pow(10, exponent);
        decimal /= 2;
        exponent++;
    }
    printf("Binary equivalent: %llu\n", binary);
    return 0;
}