//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include<stdio.h>
#include<math.h>

void convertToBinary(int decimalNum, int *binaryArr, int n) {
    /*
    A function that converts an integer decimal number to its binary equivalent and stores
    each binary digit in an array
    Inputs:
        decimalNum - the decimal number to be converted
        binaryArr - the array to store the binary digits in
        n - the size of the binary array
    Outputs:
        None (modifies the binaryArr array in place)
     */
    int i = n-1;
    while(decimalNum > 0) {
        binaryArr[i] = decimalNum % 2;
        decimalNum /= 2;
        i--;
    }
}

int main() {
    int decimalNum = 1298; //Example decimal number
    int n = 10; //Example binary array size
    int binaryArr[n];
    
    //Convert the decimal number to binary and store in the binary array
    convertToBinary(decimalNum, binaryArr, n);
    
    printf("Decimal number: %d\nBinary number: ", decimalNum);
    for(int i=0; i<n; i++) {
        printf("%d", binaryArr[i]);
    }
    printf("\n");
    
    return 0;
}