//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: systematic
#include <stdio.h>
#include <string.h>

void convertToHex(int num) {
    char hex[50];
    int i = 0;
    while (num != 0) {
        int remainder = num % 16;
        if (remainder < 10) {
            hex[i++] = remainder + 48;
        } else {
            hex[i++] = remainder + 55;
        }
        num /= 16;
    }
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    convertToHex(num);
    return 0;
}