//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declaration
void tutorial();
void gameStart();
void gameOver();
void gameWin();
void checkLocation();
void startJourney();
void continueJourney();
void rest();
void hunt();
void shop();
void showInventory();

// player struct
struct Player {
    char name[50];
    int health;
    int hunger;
    int money;
    int location;
    int arrows;
    int food;
    int water;
    int potion;
};

// main function
int main() {
    tutorial();
    gameStart();
    return 0;
}

// function to display tutorial
void tutorial() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("In this game, you will be playing as an adventurer who is traveling across a dangerous wilderness.\n");
    printf("You need to manage your health, hunger, and money while you travel towards your destination.\n");
    printf("You will face challenges like finding food and water, avoiding dangers, and maybe even hunting animals.\n");
    printf("Type 'help' any time to display available commands.\n");
    printf("\n");
}

// function to start the game
void gameStart() {
    // initialize player
    struct Player player;
    strcpy(player.name, "Adventurer");
    player.health = 100;
    player.hunger = 50;
    player.money = 100;
    player.location = 0;
    player.arrows = 10;
    player.food = 10;
    player.water = 10;
    player.potion = 0;
    
    printf("You are starting your journey as an adventurer!\n");
    printf("Your goal is to reach the other side of the wilderness.\n");
    printf("Your game will end if your health or hunger reaches 0 or if you run out of money.\n");
    printf("You are currently at the starting location.\n");
    printf("\n");
    
    // start journey
    startJourney(&player);
}

// function to handle game over
void gameOver() {
    printf("Game Over!\n");
    printf("Sorry, you didn't make it to the other side of the wilderness.\n");
    exit(0);
}

// function to handle game win
void gameWin() {
    printf("Congratulations! You have successfully made it to the other side of the wilderness!\n");
    exit(0);
}

// function to check player's location
void checkLocation(struct Player *player) {
    switch(player->location) {
        case 0:
            printf("You are currently at the starting location.\n");
            break;
        case 1:
            printf("You are in a forest.\n");
            break;
        case 2:
            printf("You are in a desert.\n");
            break;
        case 3:
            printf("You are in a mountain.\n");
            break;
        case 4:
            printf("You are near a river.\n");
            break;
        case 5:
            printf("You are in a city.\n");
            break;
        default:
            break;
    }
}

// function to start the journey
void startJourney(struct Player *player) {
    printf("What would you like to do?\n");
    while (player->location != 5) {
        char command[256];
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // remove '\n'
        
        if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("status - display player status\n");
            printf("map - display the map\n");
            printf("continue - continue the journey\n");
            printf("rest - rest to regain health and hunger\n");
            printf("hunt - hunt for food and water\n");
            printf("shop - go to the shop to buy/sell items\n");
        } else if (strcmp(command, "status") == 0) {
            printf("Name: %s\n", player->name);
            printf("Health: %d\n", player->health);
            printf("Hunger: %d\n", player->hunger);
            printf("Money: %d\n", player->money);
            printf("Location: %d\n", player->location);
            printf("\n");
        } else if (strcmp(command, "map") == 0) {
            printf("+=====+=====+=====+=====+=====+=====+\n");
            printf("|  0  |  1  |  2  |  3  |  4  |  5  |\n");
            printf("+=====+=====+=====+=====+=====+=====+\n");
            printf("|  *  |     |     |     |     |     |\n");
            printf("+-----+-----+-----+-----+-----+-----+\n");
            printf("* is your current location.\n");
        } else if (strcmp(command, "continue") == 0) {
            continueJourney(player);
        } else if (strcmp(command, "rest") == 0) {
            rest(player);
        } else if (strcmp(command, "hunt") == 0) {
            hunt(player);
        } else if (strcmp(command, "shop") == 0) {
            shop(player);
        } else {
            printf("Invalid command! Type 'help' to display available commands.\n");
        }
    }
    gameWin();
}

// function to continue the journey
void continueJourney(struct Player *player) {
    int distance = rand() % 10 + 1;
    int hazard = rand() % 4;
    player->hunger -= (rand() % 5 + 1); // player gets hungry during travel
    if (player->hunger < 0) {
        player->hunger = 0;
        player->health -= (rand() % 5 + 1); // player loses health if hunger is too low
    }
    player->money -= (rand() % 20 + 1); // player's money decreases during travel
    if (player->money < 0) {
        player->money = 0;
    }
    player->location += distance; // player moves to a new location
    checkLocation(player); // display current location
    
    if (hazard == 0) { // player encounters a wild animal
        printf("Oh no! You encountered a wild animal!\n");
        if (player->arrows >= 1) { // player can shoot arrows to kill animal
            player->arrows--;
            printf("You killed the animal and gained some food and water!\n");
            player->food += (rand() % 3 + 1);
            player->water += (rand() % 3 + 1);
        } else { // player doesn't have any arrows so must run away
            printf("You didn't have any arrows to defend yourself and had to run away!\n");
            player->health -= (rand() % 10 + 1);
            if (player->health <= 0) {
                gameOver();
            } else {
                printf("You lost some health but managed to escape.\n");
            }
        }
    } else if (hazard == 1) { // player encounters a bandit
        printf("Oh no! You encountered a bandit!\n");
        if (player->money >= (rand() % 30 + 1)) { // player has enough money to pay off bandit
            player->money -= (rand() % 30 + 1);
            printf("You paid off the bandit and avoided a fight!\n");
        } else { // player doesn't have enough money so must fight
            printf("You didn't have enough money to pay off the bandit and had to fight!\n");
            player->health -= (rand() % 20 + 1);
            if (player->health <= 0) {
                gameOver();
            } else {
                printf("You won the fight but lost some health.\n");
            }
        }
    } else if (hazard == 2) { // player encounters a natural disaster
        printf("Oh no! You encountered a natural disaster!\n");
        printf("You lost some items and suffered some damage!\n");
        player->food -= (rand() % 5 + 1);
        player->water -= (rand() % 5 + 1);
        player->arrows -= (rand() % 5 + 1);
        player->health -= (rand() % 30 + 1);
        if (player->health <= 0) {
            gameOver();
        }
    }
}

// function to rest and regain health/hunger
void rest(struct Player *player) {
    printf("You decided to rest for a while.\n");
    player->health += (rand() % 20 + 1);
    player->hunger += (rand() % 10 + 1);
    if (player->health > 100) {
        player->health = 100;
    }
    if (player->hunger > 50) {
        player->hunger = 50;
    }
    printf("You feel refreshed and ready to continue your journey.\n");
}

// function to hunt for food and water
void hunt(struct Player *player) {
    printf("You decided to go hunting for food and water.\n");
    int success = rand() % 2;
    if (success == 0) { // player failed to hunt
        printf("Unfortunately, you didn't manage to find any food or water this time.\n");
    } else { // player succeeded in hunting
        printf("You successfully hunted for food and water!\n");
        player->food += (rand() % 3 + 1);
        player->water += (rand() % 3 + 1);
    }
}

// function to go to the shop
void shop(struct Player *player) {
    printf("You arrived at the shop.\n");
    printf("Available items:\n");
    printf("1. Arrow (10) - 20 gold\n");
    printf("2. Food (1) - 10 gold\n");
    printf("3. Water (1) - 10 gold\n");
    printf("4. Health Potion (1) - 50 gold\n");
    printf("Enter command (buy/sell/exit):\n");
    char command[256];
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0'; // remove '\n'
    
    if (strcmp(command, "buy") == 0) { // player wants to buy something
        printf("Enter item number:\n");
        int item;
        scanf("%d", &item);
        getchar(); // remove '\n' from input buffer
        switch(item) {
            case 1: // arrow
                if (player->money >= 20) {
                    player->money -= 20;
                    player->arrows += 10;
                    printf("You bought 10 arrows!\n");
                } else {
                    printf("Sorry, you don't have enough gold.\n");
                }
                break;
            case 2: // food
                if (player->money >= 10) {
                    player->money -= 10;
                    player->food += 1;
                    printf("You bought 1 food!\n");
                } else {
                    printf("Sorry, you don't have enough gold.\n");
                }
                break;
            case 3: // water
                if (player->money >= 10) {
                    player->money -= 10;
                    player->water += 1;
                    printf("You bought 1 water!\n");
                } else {
                    printf("Sorry, you don't have enough gold.\n");
                }
                break;
            case 4: // health potion
                if (player->money >= 50) {
                    player->money -= 50;
                    player->potion += 1;
                    printf("You bought 1 health potion!\n");
                } else {
                    printf("Sorry, you don't have enough gold.\n");
                }
                break;
            default:
                printf("Invalid item number!\n");
                break;
        }
    } else if (strcmp(command, "sell") == 0) { // player wants to sell something
        showInventory(player);
        printf("Enter item number:\n");
        int item;
        scanf("%d", &item);
        getchar(); // remove '\n' from input buffer
        switch(item) {
            case 1: // arrow
                if (player->arrows >= 10) {
                    player->arrows -= 10;
                    player->money += 10;
                    printf("You sold 10 arrows!\n");
                } else {
                    printf("Sorry, you don't have enough arrows to sell.\n");
                }
                break;
            case 2: // food
                if (player->food >= 1) {
                    player->food -= 1;
                    player->money += 5;
                    printf("You sold 1 food!\n");
                } else {
                    printf("Sorry, you don't have enough food to sell.\n");
                }
                break;
            case 3: // water
                if (player->water >= 1) {
                    player->water -= 1;
                    player->money += 5;
                    printf("You sold 1 water!\n");
                } else {
                    printf("Sorry, you don't have enough water to sell.\n");
                }
                break;
            case 4: // health potion
                if (player->potion >= 1) {
                    player->potion -= 1;
                    player->money += 25;
                    printf("You sold 1 health potion!\n");
                } else {
                    printf("Sorry, you don't have any health potions to sell.\n");
                }
                break;
            default:
                printf("Invalid item number!\n");
                break;
        }
    } else if (strcmp(command, "exit") != 0) { // invalid command
        printf("Invalid command! Type 'buy', 'sell', or 'exit'.\n");
    }
}

// function to display player's inventory
void showInventory(struct Player *player) {
    printf("Inventory:\n");
    printf("1. Arrows - %d\n", player->arrows);
    printf("2. Food - %d\n", player->food);
    printf("3. Water - %d\n", player->water);
    printf("4. Health Potion - %d\n", player->potion);
}