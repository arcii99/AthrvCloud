//FormAI DATASET v1.0 Category: Binary Converter ; Style: real-life
#include<stdio.h>
#include<string.h>

int main(){
    int num, binaryNum[32], i=0, j;
    printf("Enter a decimal number to convert to binary: ");
    scanf("%d",&num);

    /* Decimal to Binary Conversion */
    while(num > 0){
        binaryNum[i] = num%2;
        num = num/2;
        i++;
    }

    /* Print Binary Value */
    printf("Binary Value: ");
    for(j=i-1; j>=0; j--){
        printf("%d",binaryNum[j]);
    }
    printf("\n");

    return 0;
}