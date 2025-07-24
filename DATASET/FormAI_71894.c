//FormAI DATASET v1.0 Category: Bitwise operations ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    int x = 8; // Represents the remaining population
    int y = 5; // Represents the available resources

    printf("In this post-apocalyptic world, there are %d survivors left.\n", x);
    printf("Unfortunately, there are only %d resources available for them to use.\n", y);

    // Bitwise OR operator sets the third bit to 1
    x |= 1 << 2;

    printf("\nDue to recent advancements in technology, the survivors were able to construct a device powered by the %d resources.\n", y);
    printf("As a result, their population has grown to %d.\n", x);
    printf("But with great power comes great responsibility, the device is now overheated and emits harmful radiation.\n");

    // Bitwise AND operator clears the second and fourth bits
    x &= ~(1 << 1);
    x &= ~(1 << 3);

    printf("\nIn order to mitigate the radiation, the survivors must reduce their population to %d.\n", x);
    printf("They have decided to implement a one-child-per-family policy.\n");
    printf("However, due to unforeseen circumstances, some families cannot have children.\n");

    // Bitwise XOR operator toggles the first and fifth bits
    x ^= 1 << 0;
    x ^= 1 << 4;

    printf("\nAfter implementing the policy, there are now %d families with children and %d without.\n", x & 0x1F, (~x) & 0x1F);
    printf("The survivors are planning to expand their population by gathering resources from other areas.\n");

    // Bitwise left shift operator multiplies y by 2
    y <<= 1;

    printf("\nWith the extra resources, the survivors are able to sustain a larger population of %d.\n", x * y);

    return 0;
}