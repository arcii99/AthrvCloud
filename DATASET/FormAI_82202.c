//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>

void hexConverter(int num);

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("Hexadecimal Number: ");
    hexConverter(num);
    return 0;
}

void hexConverter(int num) {
    int rem = num % 16;
    if(num == 0) {
        return;
    }
    hexConverter(num/16);
    switch(rem) {
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        default:
            printf("%d", rem);
            break;
    }
}