//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdint.h>

#define MAX_INPUT_SIZE 16

void print_hex(const uint8_t* arr, int len)
{
    for(int i=0; i<len; i++) {
        if(i%16 == 0) {
            printf("\n");
        }
        printf("%02hhX ", arr[i]);
    }
}

int main()
{
    char input[MAX_INPUT_SIZE + 1];
    printf("Enter a number in decimal format (max %d digits) : ", MAX_INPUT_SIZE);
    scanf("%s", input);

    uint64_t num = 0;
    for(int i=0; input[i] != 0; i++) {
        num = num * 10 + (input[i] - '0');
        if(num > 0xFFFFFFFFFFFFFFFF) {
            printf("The number you entered is too large\n");
            return -1;
        }
    }

    printf("\nThe Hexadecimal Equivalent of %lu is : \n\n", num);

    uint8_t hex_arr[16] = {0};
    int idx = 15;
    while(num != 0) {
        hex_arr[idx--] = num % 16;
        num /= 16;
    }
    print_hex(hex_arr, 16);
    printf("\n");
    return 0;
}