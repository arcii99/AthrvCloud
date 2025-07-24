//FormAI DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char binary[17], decimal[17] = "0000000000000000";
    int decimal_num=0, i, power;
    printf("Enter a binary number (must be 16 bits): ");
    scanf("%16s", binary); //read only 16 bits
    //converting binary to decimal
    for(i=0; i<strlen(binary); i++){
        if(binary[i] == '1'){
            power = pow(2, (strlen(binary)-i-1)); //reverse order
            decimal_num += power;
        }
    }
    //converting decimal back to binary
    i=0;
    while(decimal_num > 0){
        if(decimal_num%2 == 0){
            decimal[i] = '0';
        }
        else{
            decimal[i] = '1';
        }
        decimal_num /= 2;
        i++;
    }
    //reverse the decimal string to get binary
    char binary_convert[17];
    int len = strlen(decimal)-1;
    for(i=0; i<strlen(decimal); i++){
        binary_convert[i] = decimal[len-i];
    }
    binary_convert[len+1] = '\0'; //add null character
    //print the results
    printf("Binary: %s\nDecimal: %d\n", binary, decimal_num);
    printf("Decimal converted back to binary: %s", binary_convert);
    return 0;
}