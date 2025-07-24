//FormAI DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include <stdio.h>

int main() {

    // Imagine a world where bits could talk
    // A world where every bit has its own identity
    
    int alpha_bit = 0b00000001; // bit at position 0, representing 'a'
    int beta_bit = 0b00000010; // bit at position 1, representing 'b'
    int gamma_bit = 0b00000100; // bit at position 2, representing 'g'
    
    // These three bits lived in harmony until one day a bitwise operator knocked on their door
    
    int bit_or = alpha_bit | beta_bit | gamma_bit; // 'a' or 'b' or 'g'
    int bit_and = alpha_bit & beta_bit; // 'a' and 'b'
    int bit_not = ~gamma_bit; // not 'g'
    int bit_xor = alpha_bit ^ gamma_bit; // 'a' xor 'g'
    
    // They were curious about what would happen if they combined their powers using bitwise operations
    
    printf("Bit OR: %d\n", bit_or); // Output: 7 (0b00000111)
    printf("Bit AND: %d\n", bit_and); // Output: 0 (0b00000000)
    printf("Bit NOT: %d\n", bit_not); // Output: -5 (0b11111011)
    printf("Bit XOR: %d\n", bit_xor); // Output: 5 (0b00000101)
    
    // The bits were amazed by the power of bitwise operators
    // They realized that they could use these operators to communicate with other bits
    // They could send messages and form communities
    
    int zeta_bit = 0b00001000; // bit at position 3, representing 'z'
    
    int bit_or_community = bit_or | zeta_bit; // 'a' or 'b' or 'g' or 'z'
    int bit_and_community = bit_and & zeta_bit; // 'a' and 'b' and 'z' (but it's impossible to exist)
    int bit_not_community = ~bit_or_community; // not ('a' or 'b' or 'g' or 'z')
    int bit_xor_community = bit_xor ^ (beta_bit | gamma_bit); // 'a' xor ('b' or 'g')
    
    // The bits could now form unique communities based on the messages they send to each other
    // They could use the power of bitwise operations to convey their ideas and thoughts
    
    printf("Bit OR Community: %d\n", bit_or_community); // Output: 15 (0b00001111)
    printf("Bit AND Community: %d\n", bit_and_community); // Output: 0 (0b00000000)
    printf("Bit NOT Community: %d\n", bit_not_community); // Output: -16 (0b11110000)
    printf("Bit XOR Community: %d\n", bit_xor_community); // Output: 1 (0b00000001)
    
    return 0;
}