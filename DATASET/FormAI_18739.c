//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>

void convert(char c);

int main() {
    printf("Enter a hexadecimal number: ");
    char hex[10];
    scanf("%s",hex);

    printf("Decimal equivalent is: ");
    for(int i=0;hex[i]!='\0';i++) {
        convert(hex[i]);
    }

    return 0;
}

void convert(char c) {
    int decimal;

    if(c>='0' && c<='9') {
        decimal = c - 48;
    }
    else if(c>='a' && c<='f') {
        decimal = c - 87;
    }
    else if(c>='A' && c<='F') {
        decimal = c - 55;
    }

    printf("%d",decimal);
}