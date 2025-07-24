//FormAI DATASET v1.0 Category: Bitwise operations ; Style: medieval
#include <stdio.h>

int main()
{
    int knight = 0b10100110; // 166 in binary (medieval knights like binary!)

    // Let's perform some bitwise operations
    int shield = 0b01001110; // 78 in binary (a proud knight always carries his shield)

    int battle_cry = knight | shield; // Combine the bits of knight and shield
    printf("The knight's battle cry is %d in decimal.\n", battle_cry);

    int war_horn = knight ^ shield; // XOR the bits of knight and shield
    printf("The knight's war horn is %d in decimal.\n", war_horn);

    int jousting_lance = knight & shield; //AND the bits of knight and shield
    printf("The knight's jousting lance is %d in decimal.\n", jousting_lance);

    int battle_flag = ~knight; // Invert all the bits of knight
    printf("The knight's battle flag is %d in decimal.\n", battle_flag);

    // Display the binary representation of each bitwise operation
    printf("Binary representation of the knight's battle cry: %d%d%d%d%d%d%d%d\n",
            (battle_cry & 0b10000000) >> 7,
            (battle_cry & 0b01000000) >> 6,
            (battle_cry & 0b00100000) >> 5,
            (battle_cry & 0b00010000) >> 4,
            (battle_cry & 0b00001000) >> 3,
            (battle_cry & 0b00000100) >> 2,
            (battle_cry & 0b00000010) >> 1,
            (battle_cry & 0b00000001));

    printf("Binary representation of the knight's war horn: %d%d%d%d%d%d%d%d\n",
            (war_horn & 0b10000000) >> 7,
            (war_horn & 0b01000000) >> 6,
            (war_horn & 0b00100000) >> 5,
            (war_horn & 0b00010000) >> 4,
            (war_horn & 0b00001000) >> 3,
            (war_horn & 0b00000100) >> 2,
            (war_horn & 0b00000010) >> 1,
            (war_horn & 0b00000001));

    printf("Binary representation of the knight's jousting lance: %d%d%d%d%d%d%d%d\n",
            (jousting_lance & 0b10000000) >> 7,
            (jousting_lance & 0b01000000) >> 6,
            (jousting_lance & 0b00100000) >> 5,
            (jousting_lance & 0b00010000) >> 4,
            (jousting_lance & 0b00001000) >> 3,
            (jousting_lance & 0b00000100) >> 2,
            (jousting_lance & 0b00000010) >> 1,
            (jousting_lance & 0b00000001));

    printf("Binary representation of the knight's battle flag: %d%d%d%d%d%d%d%d\n",
            (battle_flag & 0b10000000) >> 7,
            (battle_flag & 0b01000000) >> 6,
            (battle_flag & 0b00100000) >> 5,
            (battle_flag & 0b00010000) >> 4,
            (battle_flag & 0b00001000) >> 3,
            (battle_flag & 0b00000100) >> 2,
            (battle_flag & 0b00000010) >> 1,
            (battle_flag & 0b00000001));

    return 0;
}