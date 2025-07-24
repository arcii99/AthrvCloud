//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: curious
#include <stdio.h>

int main() {
    int num;
    char hex[100];
    int i = 0;
    
    printf("Welcome! This is a unique C Hexadecimal Converter.\n\n");
    
    printf("Please enter a decimal number: ");
    scanf("%d", &num);
    
    while (num != 0) {
        int temp = 0;
        temp = num % 16;
        
        if (temp < 10) {
            hex[i] = temp + 48;
            i++;
        } else {
            hex[i] = temp + 55;
            i++;
        }
        
        num = num / 16;
    }
    
    printf("\nYour decimal number in hex is: ");
    for (int j = i-1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    
    return 0;
}