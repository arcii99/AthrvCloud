//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    char hex[17];
    int index = 0;

    while(num != 0) {
        int remainder = num % 16;
        if(remainder < 10) {
            hex[index] = 48 + remainder;
        } else {
            hex[index] = 55 + remainder;
        }
        num /= 16;
        index++;
    }

    printf("Hexadecimal number is: ");
    for(int i = index - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }

    return 0;
}