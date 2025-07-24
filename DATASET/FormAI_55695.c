//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void intro();
void dragon_intro();
void fight_dragon();
void treasure();
void game_over();
int roll_dice();
void clear_buffer();

int main()
{
    intro();
    dragon_intro();
    fight_dragon();
    treasure();
    return 0;
}

void intro()
{
    printf("Welcome to the Dragon's Cave!\n");
    printf("You are an adventurer searching for treasure.\n");
    printf("You have heard rumors of a dragon guarding a horde of treasure.\n");
    printf("You have arrived at the mouth of the cave.\n");
    printf("Enter if you dare!\n");
}

void dragon_intro()
{
    printf("\nAs you enter the cave, you hear a loud roar.\n");
    printf("A huge dragon appears in front of you!\n");
}

void fight_dragon()
{
    int player_health = 100;
    int dragon_health = 1000;

    printf("\nYou must defeat the dragon to claim the treasure!\n");

    while (player_health > 0 && dragon_health > 0)
    {
        int player_attack = roll_dice();
        printf("\nYou attack the dragon for %d damage!\n", player_attack);
        dragon_health -= player_attack;

        if (dragon_health <= 0)
        {
            printf("\nYou defeated the dragon!\n");
            return;
        }

        int dragon_attack = roll_dice() * 10;
        printf("\nThe dragon attacks you for %d damage!\n", dragon_attack);
        player_health -= dragon_attack;

        if (player_health <= 0)
        {
            game_over();
        }
    }
}

void treasure()
{
    printf("\nYou claim the treasure hoard of the dragon!\n");
    printf("You are now a legend among adventurers!\n");
}

int roll_dice()
{
    srand(time(NULL));
    return rand() % 50 + 1;
}

void game_over()
{
    printf("\nYou have been defeated by the dragon.\n");
    printf("Game over.\n");
    exit(0);
}

void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}