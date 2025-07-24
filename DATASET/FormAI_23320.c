//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char hex[17];
    long decimal, place;
    int i = 0, val, len;

    printf("Enter Hexadecimal Number: ");
    fgets(hex, sizeof(hex), stdin);
    hex[strcspn(hex, "\n")] = 0;

    len = strlen(hex);
    decimal = 0;
    place = 1;

    //Convert hexadecimal to decimal
    for (i = len - 1; i >= 0; i--) {
        if (isdigit(hex[i])) {
            val = hex[i] - '0';
        }
        else if (islower(hex[i])) {
            val = hex[i] - 'a' + 10;
        }
        else {
            val = hex[i] - 'A' + 10;
        }
        decimal += val * place;
        place *= 16;
    }

    printf("Hexadecimal Number = %s\n", hex);
    printf("Decimal Number = %ld\n", decimal);

    return 0;
}