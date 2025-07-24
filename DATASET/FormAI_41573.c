//FormAI DATASET v1.0 Category: Binary Converter ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Function to convert decimal to binary
void decToBinary(int decimal_value, char* binary_value) {
    int binary_num[32];
    int i = 0;
    while (decimal_value > 0) {
        binary_num[i] = decimal_value % 2;
        decimal_value = decimal_value / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        strcat(binary_value, binary_num[j] ? "1" : "0");
}

int main() {
    int decimal_value;
    char binary_value[33] = "";
    printf("Enter Decimal Number: ");
    scanf("%d", &decimal_value);

    // Convert decimal to binary
    decToBinary(decimal_value, binary_value);
    printf("Binary Value: %s\n", binary_value);

    return 0;
}