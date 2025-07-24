//FormAI DATASET v1.0 Category: Binary Converter ; Style: retro
#include <stdio.h>
#include <string.h>

/* Function to convert decimal to binary */
void dec_to_bin(int decimal_num, char *binary_num) {

    /* If decimal number is 0 */
    if (decimal_num == 0) {
        binary_num[0] = '0';
        binary_num[1] = '\0';
    }
    else {
        int index = 0;
        /* Repeatedly divide the decimal number by 2 and store the remainder */
        while (decimal_num > 0) {
            binary_num[index++] = (decimal_num % 2) + '0';
            decimal_num = decimal_num / 2;
        }
        binary_num[index] = '\0';

        /* Reverse the binary number */
        int i;
        int len = strlen(binary_num);
        for (i = 0; i < len / 2; i++) {
            char temp = binary_num[i];
            binary_num[i] = binary_num[len-i-1];
            binary_num[len-i-1] = temp;
        }
    }

}

int main() {
    int decimal_num;
    char binary_num[100];
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    dec_to_bin(decimal_num, binary_num);
    printf("The binary equivalent of %d is %s\n", decimal_num, binary_num);
    return 0;
}