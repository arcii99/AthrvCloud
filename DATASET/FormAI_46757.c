//FormAI DATASET v1.0 Category: Bitwise operations ; Style: medieval
#include <stdio.h>

int main() {
    int knight_hp = 100; // Knight's health points
    int enemy_attack = 20; // Enemy's attack power
    int castle_defense = 5; // Castle's defense rating
    int enemy_damage = ((enemy_attack << 1) & 0xFF) - castle_defense; // Enemy's inflicted damage
    knight_hp &= ~enemy_damage; // Knight's reduced health points
    printf("Knight's remaining HP: %d", knight_hp);
    return 0;
}