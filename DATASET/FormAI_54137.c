//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[20];
    int health;
    int attack;
    int credits;
} Player;

typedef struct {
    char name[20];
    int health;
    int attack;
} Alien;

void initialize_game(Player *player);
void create_alien(Alien *alien);
void battle(Player *player, Alien *alien);

int main() {
    Player player;
    Alien alien;
    srand(time(NULL));
    
    printf("Welcome to Procedural Space Adventure!\n");
    printf("This game is all about exploring the galaxy and battling alien creatures.\n\n");
    
    initialize_game(&player);
    create_alien(&alien);
    battle(&player, &alien);
    
    return 0;
}

void initialize_game(Player *player) {
    printf("Please enter your name: ");
    fgets(player->name, 20, stdin);
    player->health = 100;
    player->attack = 10;
    player->credits = 0;
    printf("\nGreetings, %s! Your starting health is %d and your attack power is %d.\n", player->name, player->health, player->attack);
}

void create_alien(Alien *alien) {
    char *names[5] = {"Zorgon", "Xalaxian", "Gorlax", "Thrint", "Valkarian"};
    int rand_num = rand() % 5;
    strcpy(alien->name, names[rand_num]);
    alien->health = rand() % 30 + 20;
    alien->attack = rand() % 5 + 5;
    printf("You have encountered a %s with %d health and %d attack power.\n", alien->name, alien->health, alien->attack);
}

void battle(Player *player, Alien *alien) {
    while (player->health > 0 && alien->health > 0) {
        printf("\nYour health is %d and %s's health is %d.\n", player->health, alien->name, alien->health);
        printf("Press any key to attack!\n");
        getchar();
        
        int player_damage = player->attack + rand() % 5;
        int alien_damage = alien->attack + rand() % 5;
        
        printf("You dealt %d damage to %s!\n", player_damage, alien->name);
        alien->health -= player_damage;
        printf("%s dealt %d damage to you!\n", alien->name, alien_damage);
        player->health -= alien_damage;
    }
    
    if (player->health <= 0) {
        printf("\nGame over! You have been defeated by the %s.\n", alien->name);
    } else {
        int credits_earned = rand() % 50 + 20;
        player->credits += credits_earned;
        printf("\nCongratulations! You have defeated the %s and earned %d credits.\n", alien->name, credits_earned);
        printf("Your total credits are now %d.\n", player->credits);
    }
}