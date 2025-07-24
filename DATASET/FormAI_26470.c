//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to get random number within a range
int randomize(int min, int max){
    return rand() % (max - min + 1) + min;
}

// function to do battle between player and monster
int doBattle(int playerHealth, int playerAttack, int monsterHealth, int monsterAttack){
    while(playerHealth > 0 && monsterHealth > 0){
        printf("\nPlayer Health: %d\nMonster Health: %d", playerHealth, monsterHealth);
        printf("\n\nIt's your turn to attack!");
        monsterHealth -= playerAttack;
        if(monsterHealth <= 0){
            printf("\nYou defeated the monster!");
            return 1;
        }
        printf("\n\nMonster's turn to attack...");
        playerHealth -= monsterAttack;
        if(playerHealth <= 0){
            printf("\n\nYou have been defeated by the monster...");
            return 0;
        }
    }
    return 0;
}

int main(){
    srand(time(NULL)); // seeding random number generator with current time

    // Game introduction
    printf("\nWelcome to The Dungeon Crawler Game!\nYou are a brave adventurer on a mission to explore a dark dungeon filled with monsters and treasures.\n\n");
    printf("You enter the dungeon and see doors leading to three different rooms.\nWhich room do you enter? (1, 2, or 3)\n");
    
    char input[10];
    fgets(input, 10, stdin);
    
    int room = atoi(input);
    if(room == 1){
        printf("\nYou enter the first room and see a fierce dragon guarding a treasure chest!");
        printf("\n\nYou must defeat the dragon to obtain the treasure!\n");

        int playerHealth = 100;
        int playerAttack = randomize(10,20);
        int dragonHealth = 150;
        int dragonAttack = 15;

        int result = doBattle(playerHealth, playerAttack, dragonHealth, dragonAttack);

        if(result == 1){
            printf("\n\nYou defeated the dragon and obtained the treasure chest! Congratulations!\n");
        } else {
            printf("\n\nGame Over. Better luck next time!\n");
            return 0; // end program if player lost the battle
        }

        // continue exploring other rooms
        printf("\n\nYou have obtained the treasure! Which room do you want to explore next? (2, or 3)\n");

        fgets(input, 10, stdin);

        room = atoi(input);
    }

    if(room == 2){
        printf("\nYou enter the second room and find a group of goblins guarding a magical staff!");
        printf("\n\nYou must defeat the goblins to obtain the staff!\n");

        int playerHealth = 100;
        int playerAttack = randomize(10,20);
        int goblinHealth = 50;
        int goblinAttack = 10;

        int result = doBattle(playerHealth, playerAttack, goblinHealth, goblinAttack);

        if(result == 1){
            printf("\n\nYou defeated the goblins and obtained the magical staff! Congratulations!\n");
        } else {
            printf("\n\nGame Over. Better luck next time!\n");
            return 0;
        }

        printf("\n\nYou have obtained the magical staff! Which room do you want to explore next? (1, or 3)\n");

        fgets(input, 10, stdin);

        room = atoi(input);
    }

    if(room == 3){
        printf("\nYou enter the third room and see a giant troll sleeping in the middle of the room!");
        printf("\n\nYou can either try to sneak past the troll or attack and defeat it to obtain the treasure chest.\nWhat do you want to do? (sneak, or attack)\n");

        fgets(input, 10, stdin);

        if(strcmp(input, "sneak\n") == 0){
            printf("\nYou tried to sneak past the troll but it wakes up and attacks you!");
            int playerHealth = 100;
            int playerAttack = randomize(10,20);
            int trollHealth = 200;
            int trollAttack = 20;

            int result = doBattle(playerHealth, playerAttack, trollHealth, trollAttack);

            if(result == 1){
                printf("\n\nYou defeated the troll and obtained the treasure chest! Congratulations!\n");
            } else {
                printf("\n\nGame Over. Better luck next time!\n");
                return 0;
            }
        } else if(strcmp(input, "attack\n") == 0){
            printf("\nYou attacked the troll and started a battle!");
            int playerHealth = 100;
            int playerAttack = randomize(10,20);
            int trollHealth = 200;
            int trollAttack = 20;

            int result = doBattle(playerHealth, playerAttack, trollHealth, trollAttack);

            if(result == 1){
                printf("\n\nYou defeated the troll and obtained the treasure chest! Congratulations!\n");
            } else {
                printf("\n\nGame Over. Better luck next time!\n");
                return 0;
            }
        } else {
            printf("\nInvalid input. Game Over. Better luck next time!\n");
            return 0;
        }

        printf("\n\nYou have obtained all the treasures and defeated all the monsters! You won the game! Congratulations!\n");
    }

    return 0;
}