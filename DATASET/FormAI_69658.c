//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

void hexToDecimal(char hexNum[]){
    int len = strlen(hexNum);
    int base = 1;
    int decimal = 0;

    for(int i=len-1; i>=0; i--){
        if(hexNum[i]>='0' && hexNum[i]<='9'){
            decimal += (hexNum[i] - 48) * base;
            base *= 16;
        }
        else if(hexNum[i]>='A' && hexNum[i]<='F'){
            decimal += (hexNum[i] - 55) * base;
            base *= 16;
        }
        else if(hexNum[i]>='a' && hexNum[i]<='f'){
            decimal += (hexNum[i] - 87) * base;
            base *= 16;
        }
        else{
            printf("Invalid Hexadecimal Number");
            return;
        }
    }
    printf("Decimal number is %d", decimal);
}

int main(){
    char hexNum[20];
    printf("Enter a Hexadecimal Number: ");
    scanf("%s", &hexNum);
    hexToDecimal(hexNum);
    return 0;
}