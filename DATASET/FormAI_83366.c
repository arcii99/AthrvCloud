//FormAI DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert_to_binary(int num);

int main(){
    int decimal_num;
    char *binary_string;

    // Take user input of a decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);

    // Convert decimal number to binary string
    binary_string = convert_to_binary(decimal_num);

    // Output the binary string
    printf("Binary equivalent of %d: %s\n", decimal_num, binary_string);

    // Free memory
    free(binary_string);

    return 0;
}

char *convert_to_binary(int num){
    int binary_num[64];
    int i = 0;

    // Convert decimal number to binary
    while(num > 0){
        binary_num[i] = num % 2;
        num /= 2;
        i++;
    }

    // Create binary string
    char *binary_string = (char*) malloc(sizeof(char) * (i+1));
    int j;
    for(j=0; j<i; j++){
        binary_string[j] = binary_num[i-j-1] + '0';
    }
    binary_string[i] = '\0';

    return binary_string;
}