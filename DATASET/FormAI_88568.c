//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Romeo and Juliet
// Romeo and Juliet in Bitwise Operations

#include <stdio.h>
#include <stdint.h>

int main()
{
    uint16_t romeo = 0b0110111001010011; // Romeo's 16-bit binary number
    uint16_t juliet = 0b0101101001100101; // Juliet's 16-bit binary number

    printf("Romeo: %04x\n", romeo);      // Print Romeo's number in hexadecimal format
    printf("Juliet: %04x\n", juliet);    // Print Juliet's number in hexadecimal format
    
    // Romeo and Juliet's first encounter
    printf("\nAs Romeo gazes upon Juliet,\n");
    
    // Romeo uses right shift to move his digits closer to Juliet's
    romeo >>= 2;
    printf("Romeo: %04x\n", romeo);
    
    // Juliet uses left shift to move her digits closer to Romeo's
    juliet <<= 4;
    printf("Juliet: %04x\n", juliet);

    // Romeo's declaration of love
    printf("\nRomeo declares his love to Juliet,\n");

    // Romeo uses bitwise OR to combine his love with Juliet's
    romeo |= juliet;
    printf("Romeo: %04x\n", romeo);
    
    // Juliet's reciprocation of love
    printf("\nJuliet reciprocates Romeo's love,\n");
    
    // Juliet uses bitwise XOR to show her love for Romeo
    juliet ^= romeo;
    printf("Juliet: %04x\n", juliet);
    
    // Romeo and Juliet's final union
    printf("\nIn the end, Romeo and Juliet unite to form one,\n");
    
    // Romeo uses bitwise AND to merge with Juliet
    romeo &= juliet;
    printf("Romeo: %04x\n", romeo);

    return 0;
}