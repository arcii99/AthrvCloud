//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#include <stdio.h>

// function to convert decimal to hexadecimal
void dec_to_hex(int n) {
    int hex[20], i = 0;
    while(n > 0) {
        hex[i] = n % 16;
        n /= 16;
        i++;
    }
    printf("The hexadecimal value is: ");
    for(int j=i-1; j>=0; j--) {
        if(hex[j] < 10)
            printf("%d", hex[j]);
        else {
            switch(hex[j]) {
                case 10: printf("A"); break;
                case 11: printf("B"); break;
                case 12: printf("C"); break;
                case 13: printf("D"); break;
                case 14: printf("E"); break;
                case 15: printf("F"); break;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter a positive decimal number to convert to hexadecimal: ");
    scanf("%d", &n);
    if(n < 0) {
        printf("Do not try to hack me by entering negative numbers!");
        return 0;
    }
    else {
        dec_to_hex(n);
    }
    return 0;
}