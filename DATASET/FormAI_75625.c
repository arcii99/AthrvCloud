//FormAI DATASET v1.0 Category: Color Code Converter ; Style: dynamic
#include <stdio.h>

int main() {
    char hex[10];
    int r, g, b;

    printf("Enter a hexadecimal color code (e.g. #FF0000): ");
    scanf("%s", hex);

    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);

    printf("RGB color code: %d, %d, %d", r, g, b);

    return 0;
}