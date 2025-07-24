//FormAI DATASET v1.0 Category: Bitwise operations ; Style: medieval
#include<stdio.h>

int main(){
    int sword = 0b1101; // binary for 13
    int shield = 0b0011; // binary for 3
    int armor = 0b1010; // binary for 10
    int gold = 0b111111; // binary for 63

    printf("Ye hath begun with a sword of %d, a shield of %d, armor of %d, and %d gold coins.\n", sword, shield, armor, gold);

    sword >>= 1; // Ye hath lost thy sword's sharpness by half!
    shield <<= 2; // Thy shield hath grown larger by twice its size!
    armor ^= 0b1111; // Thou hath changed thy armor to a different kind!
    gold &= ~0b1010; // Thou hast traded in 10 gold coins to the merchant!

    printf("Ye hath returned with a sword of %d, a shield of %d, armor of %d, and %d gold coins.\n", sword, shield, armor, gold);

    return 0;
}