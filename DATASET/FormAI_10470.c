//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Romeo and Juliet
// Romeo and Juliet's Bitwise Love Story

#include <stdio.h>
#include <stdlib.h>

int main() {

    unsigned int romeo = 0b11001101;
    unsigned int juliet = 0b01010110;
    
    // Romeo and Juliet's hearts beat as one
    unsigned int love = romeo & juliet;
    
    // Romeo sends his love to Juliet
    unsigned int love_letter = romeo | juliet;

    // Juliet receives her love from Romeo
    unsigned int love_received = love_letter & juliet;
    
    // Romeo and Juliet's love will never die
    unsigned int eternal_love = ~0;
    
    // Romeo and Juliet's love is too strong for adversity
    unsigned int adversity = 0b01110011;
    unsigned int strong_love = love | adversity;
    
    // Romeo and Juliet's love will create something new
    unsigned int new_life = romeo ^ juliet;
    
    // Romeo and Juliet join their lives together
    unsigned int joined_life = romeo << 4 | juliet >> 4;
    
    // Romeo and Juliet's love is worth more than gold
    unsigned int gold = 0xA0;
    unsigned int true_love = ((romeo & gold) << 1) + ((juliet | gold) >> 1);

    // Romeo and Juliet's love will always remain a mystery
    unsigned int mystery = 0b10101010;
    unsigned int masked_love = love & mystery;

    // Romeo and Juliet's love will never fade away
    unsigned int fade_away = 0b00100010;
    unsigned int constant_love = love | fade_away;

    printf("Romeo's love letter to Juliet: %d\n", love_letter);
    printf("Juliet's love received from Romeo: %d\n", love_received);
    printf("Romeo and Juliet's hearts beat as one: %d\n", love);
    printf("Romeo and Juliet's love is too strong for adversity: %d\n", strong_love);
    printf("Romeo and Juliet's love will create something new: %d\n", new_life);
    printf("Romeo and Juliet join their lives together: %d\n", joined_life);
    printf("Romeo and Juliet's love is worth more than gold: %d\n", true_love);
    printf("Romeo and Juliet's love will always remain a mystery: %d\n", masked_love);
    printf("Romeo and Juliet's love will never fade away: %d\n", constant_love);

    return 0;
}