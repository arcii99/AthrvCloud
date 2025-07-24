//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
    char hexadecimal[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int decimal, rem, i = 0;
    char hex[20];
    
    printf("Enter decimal number: ");
    scanf("%d", &decimal);
    
    while (decimal > 0) {
        rem = decimal % 16;
        hex[i] = hexadecimal[rem];
        decimal /= 16;
        i++;
    }
    
    printf("The hexadecimal equivalent is: ");
    
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    
    return 0;
}