//FormAI DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to my Binary Converter Program!\n");
    
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    
    int binary[32]; // array to store binary digits
    int i = 0; // counter
    
    while(num > 0) {
        binary[i] = num % 2; // store remainder in array
        num = num / 2; // update num value
        i++; // increment counter
    }
    
    printf("The binary representation of the number is: ");
    
    // print the binary digits in reverse order (starting from the end of the array)
    for(int j = i-1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    
    printf("\n");
    return 0;
}