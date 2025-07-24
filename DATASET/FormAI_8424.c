//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void purify(char*);
void teleport();
void spaceWalk();
void engage();
void attack();

int health = 100;
int enemiesRemaining = 10;

int main() {
    char input[100];
    srand(time(NULL));
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("Your mission is to defeat the evil aliens and save the universe.\n");
    printf("You start with 100 Health Points.\n");
    printf("Type 'help' for list of commands.\n\n");
    
    while(health > 0 && enemiesRemaining > 0) {
        printf("Enter your command: ");
        fgets(input, 100, stdin);
        purify(input);
        
        if(strcmp(input, "help") == 0) {
            printf("Commands:\n");
            printf("> teleport\n");
            printf("> spacewalk\n");
            printf("> engage\n");
            printf("> attack\n");
            printf("> help\n\n");
        } else if(strcmp(input, "teleport") == 0) {
            teleport();
        } else if(strcmp(input, "spacewalk") == 0) {
            spaceWalk();
        } else if(strcmp(input, "engage") == 0) {
            engage();
        } else if(strcmp(input, "attack") == 0) {
            attack();
        } else {
            printf("Invalid command. Type 'help' for list of commands.\n\n");
        }
    }
    
    if(health <= 0) {
        printf("Game Over. You ran out of Health Points.\n");
    } else {
        printf("Congratulations! You have defeated all the enemies and saved the universe.\n");
    }
    
    return 0;
}

void purify(char* input) {
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == '\n') {
            input[i] = '\0';
        }
    }
}

void teleport() {
    int chance = rand() % 10 + 1;
    if(chance <= 5) {
        printf("Teleportation failed. You lost 10 Health Points.\n\n");
        health -= 10;
    } else {
        printf("Teleportation successful. You are in a room with enemies.\n\n");
        enemiesRemaining = 10;
    }
}

void spaceWalk() {
    int chance = rand() % 10 + 1;
    if(chance <= 4) {
        printf("Spacewalk successful. You found a medkit and regained 20 Health Points.\n\n");
        health += 20;
    } else {
        printf("Spacewalk failed. You lost 10 Health Points due to exposure.\n\n");
        health -= 10;
    }
}

void engage() {
    if(enemiesRemaining > 0) {
        printf("You are in a room with %d enemies. Kill them all to proceed.\n\n", enemiesRemaining);
    } else {
        printf("You have already defeated all the enemies in this room.\n\n");
    }
}

void attack() {
    if(enemiesRemaining > 0) {
        int damage = rand() % 20 + 5;
        printf("You attacked an enemy and dealt %d damage.\n", damage);
        enemiesRemaining--;
        if(enemiesRemaining == 0) {
            printf("You have defeated all the enemies in this room.\n\n");
        } else {
            printf("%d enemies remaining in this room.\n\n", enemiesRemaining);
        }
    } else {
        printf("There are no enemies left in this room to attack.\n\n");
    }
}