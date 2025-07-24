//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>

const int MAX_LENGTH = 100;

int main() {
    
    char hex_num[MAX_LENGTH];
    int decimal_num = 0;
    int power = 1;
    int num_digits = 0;
    
    printf("Welcome to the Hexadecimal Converter! \n");
    
    printf("Please enter a valid hexadecimal number: ");
    scanf("%s", hex_num);
    
    for(int i = 0; hex_num[i] != '\0'; i++){
        num_digits++;
    }
    
    for(int i = num_digits - 1; i >= 0; i--){
        int digit = 0;
        if(hex_num[i] >= '0' && hex_num[i] <= '9'){
            digit = hex_num[i] - '0';
        }
        else if(hex_num[i] >= 'a' && hex_num[i] <= 'f'){
            digit = hex_num[i] - 'a' + 10;
        }
        else if(hex_num[i] >= 'A' && hex_num[i] <= 'F'){
            digit = hex_num[i] - 'A' + 10;
        }
        else{
            printf("Invalid hexadecimal number, please try again. \n");
            return 1;
        }
        decimal_num += digit * power;
        power *= 16;
    }
    
    printf("The equivalent decimal number is: %d \n", decimal_num);
    
    return 0;
    
}