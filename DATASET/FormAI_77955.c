//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdint.h>

#define BIT_SET(p,n) ((p) |= (1u << (n)))
#define BIT_CLEAR(p,n) ((p) &= ~(1u << (n)))
#define BIT_TEST(p,n) (((p) & (1u << (n))) != 0)

int main() {
    uint8_t flags = 0b00101111;
    uint8_t option1 = 0;
    uint8_t option2 = 0;
    uint8_t option3 = 0;

    printf("Welcome to Ken's Bitwise Operation Program!\n\n");
    printf("Current flags: %u\n\n", flags);

    // Turning on option 1 (bit 0)
    if (!BIT_TEST(flags, 0)) {
        BIT_SET(flags, 0);
        option1 = 1;
    }

    // Turning off option 2 (bit 3)
    if (BIT_TEST(flags, 3)) {
        BIT_CLEAR(flags, 3);
        option2 = 1;
    }

    // Toggling option 3 (bit 5)
    if (BIT_TEST(flags, 5)) {
        BIT_CLEAR(flags, 5);
    } else {
        BIT_SET(flags, 5);
    }
    option3 = BIT_TEST(flags, 5);

    printf("Option 1 is %s\n", option1 ? "ON" : "OFF");
    printf("Option 2 is %s\n", option2 ? "OFF" : "ON");
    printf("Option 3 is %s\n\n", option3 ? "ON" : "OFF");
    printf("New flags: %u\n", flags);

    return 0;
}