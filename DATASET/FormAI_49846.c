//FormAI DATASET v1.0 Category: Educational ; Style: Cyberpunk
#include<stdio.h>

// Function to calculate the power of a number
int power(int base, int exp){
    int res = 1;
    for(int i=0;i<exp;i++){
        res = res * base;
    }
    return res;
}

int main(){
    int num, binaryNum = 0, i = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    while(num>0){
        binaryNum += (num%2) * power(10, i);
        num /= 2;
        i++;
    }
    printf("Binary Equivalent is: %d\n", binaryNum);
    return 0;
}