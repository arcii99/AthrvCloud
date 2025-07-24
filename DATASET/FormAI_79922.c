//FormAI DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* binaryConvert(int number) {
    char* binary = (char*) malloc(33 * sizeof(char));
    int i = 0;
    while(number != 0) {
        binary[i++] = (number % 2) + '0';
        number /= 2;
    }
    binary[i] = '\0';
    int len = strlen(binary);
    for(int i=0; i<len/2; i++) {
        char temp = binary[i];
        binary[i] = binary[len-i-1];
        binary[len-i-1] = temp;
    }
    return binary;
}

int main() {
    int num;
    printf("Enter any integer number: ");
    scanf("%d", &num);
    if(num < 0) {
        printf("Invalid input\n");
        return 0;
    }
    char* binary = binaryConvert(num);
    printf("Binary conversion: %s\n", binary);
    free(binary);
    return 0;
}