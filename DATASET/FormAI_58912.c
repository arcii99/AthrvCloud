//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hex[] = "0123456789ABCDEF";

int main() {
    char input[50];
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    sprintf(input, "%X", decimal);
    printf("The hexadecimal equivalent of %d is %s\n", decimal, input);
    int len = strlen(input);
    printf("Breaking it down into individual bytes: ");
    for(int i = 0; i < len; i+=2) {
        char byte[3] = {input[i], input[i+1], '\0'};
        int byteDec = strtol(byte, NULL, 16);
        printf("%d ", byteDec);
    }
    printf("\n");
    return 0;
}