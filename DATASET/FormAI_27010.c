//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>

int main() {
    int n, i = 0, j;
    char hex[100];
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    while (n != 0) {
        int rem = n % 16;
        if (rem < 10) {
            hex[i++] = rem + 48;
        } else {
            hex[i++] = rem + 55;
        }
        n = n / 16;
    }
    printf("Hexadecimal number: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    return 0;
}