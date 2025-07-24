//FormAI DATASET v1.0 Category: Binary Converter ; Style: Cryptic
#include<stdio.h>

void binaryConverter(int num) {
    if (num > 1)
        binaryConverter(num / 2);
    printf("%d", num % 2);
}

int main() {

    // Let's keep it cryptic ;)
    int decimal = 73656;
    printf("Decoding binary sequence...\n");
    binaryConverter(decimal);
    printf("\nDecoded successfully.\n");

    return 0;
}