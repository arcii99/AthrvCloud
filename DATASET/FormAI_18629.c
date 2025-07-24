//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include <stdio.h>

int main() {
    float tempIn, tempOut;
    char convert;

    printf("Enter the temperature: ");
    scanf("%f", &tempIn);

    printf("Convert to (C)elsius or (F)ahrenheit? ");
    scanf(" %c", &convert);

    tempOut = (convert == 'C') ? (tempIn * 9/5) + 32 : (tempIn - 32) * 5/9;

    printf("Temperature: %.2f%c\n", tempOut, (convert == 'C' ? 'F' : 'C'));

    return 0;
}