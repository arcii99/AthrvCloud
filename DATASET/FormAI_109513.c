//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: happy
#include <stdio.h>

int main() {
    printf("Welcome to the Happy Hexadecimal Converter!\n");
    printf("What decimal number would you like to convert to hexadecimal?\n");
    
    int decimal;
    scanf("%d", &decimal);
    
    printf("Your decimal number %d in hexadecimal is ", decimal);
    
    char hexadecimal[100];
    int index = 0;
    
    while(decimal != 0) {
        int remainder = decimal % 16;
        if(remainder < 10) {
            hexadecimal[index] = remainder + '0';
        } else {
            hexadecimal[index] = remainder - 10 + 'A';
        }
        index++;
        decimal /= 16;
    }
    
    for(int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
    
    printf("\nThank you for using the Happy Hexadecimal Converter!");
    
    return 0;
}