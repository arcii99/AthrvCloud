//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Alan Touring
#include <stdio.h>
#include <ctype.h>

int main() {
    char hex_num[10];
    int dec_num = 0, i, j, power = 1;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_num);
    for (i = strlen(hex_num) - 1; i >= 0; i--) {
        if (hex_num[i] >= '0' && hex_num[i] <= '9') {
            dec_num += (hex_num[i] - '0') * power;
        } else if (toupper(hex_num[i]) >= 'A' && toupper(hex_num[i]) <= 'F') {
            dec_num += (toupper(hex_num[i]) - 'A' + 10) * power;
        }
        power *= 16;
    }
    printf("Decimal number is %d\n", dec_num);
    return 0;
}