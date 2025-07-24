//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

typedef struct {
    char* name;
    int health;
    int attack;
    int defense;
    int food;
} Player;

typedef struct {
    char* name;
    int health;
    int attack;
} Enemy;

void printIntro() {
    printf("Welcome to the post-apocalyptic wasteland.\n");
    delay(2000);
    printf("The world has been devastated by an unknown disease\n");
    delay(2000);
    printf("As a survivor, you must fight to keep yourself alive\n");
    delay(2000);
    printf("You find yourself in the ruins of an old city.\n");
    delay(2000);
    printf("To stay alive, you'll need to scavenge for supplies and fend off enemies.\n");
    delay(2000);
    printf("Good luck.\n");
}

void checkInput(char* input, Player* player) {
    if (strcmp(input, "stats") == 0) {
        printf("Name: %s\n", player->name);
        printf("Health: %d\n", player->health);
        printf("Attack: %d\n", player->attack);
        printf("Defense: %d\n", player->defense);
        printf("Food: %d\n", player->food);
    } 
    else if (strcmp(input, "explore") == 0) {
        int chance = rand() % 10;
        if (chance < 4) {
            printf("You were attacked by a wild dog!\n");
            Enemy dog = {"Wild Dog", 30, 10};
            battle(&dog, player);
        } 
        else if (chance < 7) {
            printf("You found some food!\n");
            player->food += 10;
        } 
        else {
            printf("You didn't find anything.\n");
        }
    } 
    else if (strcmp(input, "rest") == 0) {
        printf("You rested for a while.\n");
        player->health += 20;
    } 
    else if (strcmp(input, "quit") == 0) {
        printf("Exiting game...\n");
        exit(0);
    } 
    else {
        printf("Invalid command. Type 'stats', 'explore', 'rest', or 'quit'.\n");
    }
}

void battle(Enemy* enemy, Player* player) {
    while (enemy->health > 0 && player->health > 0) {
        printf("You attack the %s for %d damage.\n", enemy->name, player->attack);
        enemy->health -= player->attack;
        if (enemy->health <= 0) {
            printf("You have defeated the %s.\n", enemy->name);
            player->food += 5;
            return;
        }
        printf("The %s attacks you for %d damage.\n", enemy->name, enemy->attack);
        player->health -= enemy->attack;
        if (player->health <= 0) {
            printf("You have been defeated by the %s.\n", enemy->name);
            exit(0);
        }
    }
}

int main() {
    srand(time(NULL));
    printIntro();
    Player player = {"Player", 100, 20, 10, 50};
    char input[20];
    while (1) {
        printf("What would you like to do? Type 'stats', 'explore', 'rest', or 'quit'.\n");
        scanf("%s", input);
        checkInput(input, &player);
    }
    return 0;
}