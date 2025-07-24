//FormAI DATASET v1.0 Category: Bitwise operations ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*-------------------------------
    Irregular Bitwise operations
---------------------------------*/

/* Function: print_byte
   Prints an 8-bit value as a binary number with leading zeroes */
void print_byte(uint8_t byte)
{
    int i;
    for(i = 7; i >= 0; --i)
    {
        printf("%d", (byte & (1 << i)) >> i);
    }
    printf("\n");
}

/* Function: nibble_swap
   Swaps the two nibbles of an 8-bit integer */
uint8_t nibble_swap(uint8_t val)
{
    uint8_t upper_nibble = (val & 0xF0) >> 4;
    uint8_t lower_nibble = (val & 0x0F) << 4;

    return (upper_nibble | lower_nibble);
}

/* Function: bit_swap
   Swaps every two adjacent bits in an 8-bit integer */
uint8_t bit_swap(uint8_t val)
{
    uint8_t swapped = 0;

    int i;
    for(i = 0; i < 8; i+=2)
    {
        swapped |= ((val & (1 << i)) << 1);
        swapped |= ((val & (1 << (i+1))) >> 1);
    }

    return swapped;
}

/* Function: nibble_rotate
   Rotates the nibbles of an 8-bit integer to the left by one position */
uint8_t nibble_rotate(uint8_t val)
{
    uint8_t upper_nibble = (val & 0xF0) >> 4;
    uint8_t lower_nibble = (val & 0x0F) << 4;

    return (lower_nibble | upper_nibble);
}

/* Function: byte_reverse
   Reverses the bits of an 8-bit integer */
uint8_t byte_reverse(uint8_t val)
{
    uint8_t rev = 0;
    int i;
    for(i = 0; i < 8; ++i)
    {
        rev |= ((val & (1 << i)) << (7 - (i * 2)));
        rev |= ((val & (1 << i)) >> (7 - (i * 2 + 1)));
    }

    return rev;
}

int main()
{
    uint8_t test_val = 0b10110110;
    printf("Original value: ");
    print_byte(test_val);

    printf("Nibble swap: ");
    print_byte(nibble_swap(test_val));

    printf("Bit swap: ");
    print_byte(bit_swap(test_val));

    printf("Nibble rotate: ");
    print_byte(nibble_rotate(test_val));

    printf("Byte reverse: ");
    print_byte(byte_reverse(test_val));

    return 0;
}