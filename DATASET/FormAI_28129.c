//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include<stdio.h>

int main(){
    int num, n1, n2, n3, n4, n5, n6, n7, n8, checksum;
    
    printf("Enter the 8-digit decimal number: ");
    scanf("%d", &num);
    
    n1 = num / 10000000 % 10;
    n2 = num / 1000000 % 10;
    n3 = num / 100000 % 10;
    n4 = num / 10000 % 10;
    n5 = num / 1000 % 10;
    n6 = num / 100 % 10;
    n7 = num / 10 % 10;
    n8 = num % 10;
    
    checksum = (n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8) % 10;
    
    printf("The checksum value is: %d", checksum);
    
    return 0;
}