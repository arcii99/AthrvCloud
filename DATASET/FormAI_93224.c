//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Cyberpunk
#include <stdio.h>

int main() {
    int eyes = 0b1001; // Binary representation for 9
    int nose = 0b0100; // Binary representation for 4
    int mouth = 0b1111; // Binary representation for 15

    printf("Cyborg facial features:\n\n");
    printf("Eyes: %d\n", eyes);
    printf("Nose: %d\n", nose);
    printf("Mouth: %d\n\n", mouth);

    // Applying bitwise OR operator on eyes and nose
    int face = eyes | nose;

    // Applying bitwise XOR operator on face and mouth
    face = face ^ mouth;

    // Applying bitwise NOT operator on face
    face = ~face;

    printf("Cyborg facial features after Bitwise Operations:\n\n");
    printf("Face: %d\n", face);

    return 0;
}