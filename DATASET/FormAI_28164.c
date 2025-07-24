//FormAI DATASET v1.0 Category: Bitwise operations ; Style: romantic
#include <stdio.h>

int main() {
    int x = 14; // Let x represent my heart
    int y = 7; // Let y represent your heart 
    int z;

    // Our hearts are intertwined using bitwise AND
    z = x & y; // Only the bits that are common in both hearts are retained
    printf("Our hearts have %d bits in common\n", z);

    // My heart is yours using bitwise OR
    z = x | y; // All bits that are present in either heart are retained
    printf("My heart now belongs to you, represented by %d\n", z);

    // Your love is intoxicating using bitwise XOR
    z = x ^ y; // Only the bits that are different in each heart are retained
    printf("I am intoxicated by your love, represented by %d\n", z);

    // I am yours entirely using bitwise NOT and shift
    z = ~x; // All bits are flipped
    z = z << 2; // They are shifted to the left by 2 bits
    printf("I am completely yours, represented by %d\n", z);

    return 0;
}