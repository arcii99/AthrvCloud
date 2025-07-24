//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: excited
#include <stdio.h>

int main() {
    
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Enter a decimal number to convert: ");
    
    int decimal;
    scanf("%d", &decimal);
    
    printf("\nConverting %d to hexadecimal...\n", decimal);
    
    int remainder;
    char hex[10];
    int i = 0;
    
    while(decimal > 0) {
        remainder = decimal % 16;
        
        if(remainder < 10) {
            hex[i] = remainder + 48; // convert to ASCII code
        } else {
            hex[i] = remainder + 55; // convert to ASCII code
        }
        
        decimal /= 16;
        i++;
    }
    
    printf("\nThe hexadecimal representation of %d is: ", decimal);
    
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    
    printf("\n\nThank you for using the Hexadecimal Converter!\n");
    
    return 0;
}