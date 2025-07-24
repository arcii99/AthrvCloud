//FormAI DATASET v1.0 Category: Binary Converter ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void binary_to_decimal(char* binary_num);
void decimal_to_binary(int decimal_num);

int main(){
    char binary[100];
    int decimal;
    printf("Enter a binary number: ");
    scanf("%s", binary);
    binary_to_decimal(binary);
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    decimal_to_binary(decimal);
    return 0;
}

//function to convert binary to decimal
void binary_to_decimal(char* binary_num){
    int len = strlen(binary_num);
    int decimal = 0;
    int power = len-1;
    for(int i=0; i<len; i++){
        if(binary_num[i] == '1'){
            decimal += pow(2, power);
        }
        power--;
    }
    printf("%s in decimal is %d\n", binary_num, decimal);
}

//function to convert decimal to binary
void decimal_to_binary(int decimal_num){
    int binary[100];
    int index = 0;
    while(decimal_num > 0){
        binary[index] = decimal_num % 2;
        decimal_num = decimal_num / 2;
        index++;
    }
    printf("%d in binary is ", decimal_num);
    for(int i=index-1; i>=0; i--){
        printf("%d", binary[i]);
    }
    printf("\n");
}