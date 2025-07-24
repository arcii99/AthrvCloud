//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int ishex(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
        return 1;
    else
        return 0;
}

int chartoint(char c) {
    int n = 0;
    if (c >= '0' && c <= '9')
        n = c - '0';
    else if (c >= 'a' && c <= 'f')
        n = c - 'a' + 10;
            else if (c >= 'A' && c <= 'F')
                n = c - 'A' + 10;
            return n;
}

int hextoint(char *hex) {
    int i = 0, n = 0;
    while (hex[i] != '\0') {
        if (ishex(hex[i])) {
            n *= 16;
            n += chartoint(hex[i]);
        }
        i++;
    }
    return n;
}

int main() {
    char hex[10];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    int n = hextoint(hex);
    printf("The decimal equivalent of %s is %d", hex, n);

    return 0;
}