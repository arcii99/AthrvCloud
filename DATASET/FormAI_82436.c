//FormAI DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>

int main() {
    // Declare variables for our futuristic operations
    int a = 6, b = 7, result;
    long c = 1234567890, d = 9876543210, long_result;
    unsigned int e = 1000, f = 2000, unsigned_result;
    unsigned long long g = 9999999999999, h = 1111111111111, long_long_result;
    
    // Perform some bitwise operations
    result = a & b;
    printf("The bitwise AND of %d and %d is %d\n", a, b, result);
    
    long_result = c | d;
    printf("The bitwise OR of %ld and %ld is %ld\n", c, d, long_result);
    
    unsigned_result = e ^ f;
    printf("The bitwise XOR of %u and %u is %u\n", e, f, unsigned_result);
    
    long_long_result = g >> 2;
    printf("The right shift of %llu by 2 is %llu\n", g, long_long_result);
    
    long_long_result = h << 3;
    printf("The left shift of %llu by 3 is %llu\n", h, long_long_result);
    
    return 0;
}