//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include<stdio.h>
#include<string.h>

void hexaConverter(int n);

int main() {

    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    printf("The hexadecimal of %d is: ", decimalNum);
    hexaConverter(decimalNum);

    return 0;
}

void hexaConverter(int n) {

    char hexaNum[100];
    int i = 0;

    while(n!=0) {
        int temp = n % 16;
        if(temp < 10) {
            hexaNum[i] = temp + 48;
            i++;
        }
        else {
            hexaNum[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }

    for(int j=i-1; j>=0; j--) {
        printf("%c", hexaNum[j]);
    }
}