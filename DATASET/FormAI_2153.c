//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: automated
#include <stdio.h>

// Function to convert decimal to hexadecimal
void decToHex(int num){
    char* hexaEquivalent = "0123456789ABCDEF";
    char hexaNum[100];
    int i = 0;
    
    // Remainder and quotient of num when divided by 16
    while(num>=16){
        int rem = num%16;
        hexaNum[i++] = hexaEquivalent[rem];
        num /= 16;
    }
    hexaNum[i] = hexaEquivalent[num];
    
    printf("Hexadecimal Value : ");
    for(int j=i;j>=0;j--){
        printf("%c", hexaNum[j]);
    }
    printf("\n");
}

int main(){
    int num;
    
    printf("Enter Decimal Number : ");
    scanf("%d",&num);
    
    decToHex(num);
    
    return 0;
}