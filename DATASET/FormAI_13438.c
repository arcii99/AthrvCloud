//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rollDice() {
    return rand() % 6 + 1;
}

void display() {
    printf("You are in a dark, damp dungeon.\n");
    printf("There are four paths to take - North, South, East, and West.\n");
    printf("Where would you like to go?\n");
    printf("Enter 'N', 'S', 'E', or 'W': ");
}

void north() {
    int result = rollDice();
    printf("You head north...\n");
    if(result <= 3) {
        printf("You encounter a small group of goblins.\n");
        printf("They attack you with rusty swords and daggers.\n");
        printf("You take 2 damage.\n");
    }
    else {
        printf("You find a treasure chest!\n");
        printf("You gain 10 gold.\n");
    }
}

void south() {
    int result = rollDice();
    printf("You head south...\n");
    if(result <= 3) {
        printf("You encounter a big troll.\n");
        printf("He charges at you with a massive club.\n");
        printf("You take 5 damage.\n");
    }
    else {
        printf("You find a potion.\n");
        printf("You gain 10 health.\n");
    }
}

void east() {
    int result = rollDice();
    printf("You head east...\n");
    if(result <= 3) {
        printf("You fall into a pit trap.\n");
        printf("You take 3 damage.\n");
    }
    else {
        printf("You find a secret passage!\n");
        printf("You gain 10 experience points.\n");
    }
}

void west() {
    int result = rollDice();
    printf("You head west...\n");
    if(result <= 3) {
        printf("You are ambushed by a group of bandits.\n");
        printf("They steal 5 gold from you.\n");
    }
    else {
        printf("You find a hidden cache of weapons and armor!\n");
        printf("You gain 20 defense.\n");
    }
}

int main() {
    srand(time(NULL));
    int health = 20;
    int gold = 25;
    int defense = 10;
    int experience = 0;
    
    printf("Welcome to the Dungeon Adventure Game!\n");
    printf("Your goal is to survive and collect as much treasure as possible.\n");
    printf("You start with 20 health, 25 gold, 10 defense, and 0 experience points.\n");
    
    while(health > 0) {
        display();
        char choice = getchar();
        getchar(); // Consume the newline character
        
        switch(choice) {
            case 'N':
            case 'n':
                north();
                break;
            case 'S':
            case 's':
                south();
                break;
            case 'E':
            case 'e':
                east();
                break;
            case 'W':
            case 'w':
                west();
                break;
            default:
                printf("Invalid input. Try again.\n");
                continue; // Go back to the top of the loop
        }
        
        printf("You have %d health, %d gold, %d defense, and %d experience points.\n", health, gold, defense, experience);
        
        // Check if the player has died
        if(health <= 0) {
            printf("You have died. Game over.\n");
            break;
        }
        
        // Increase the player's experience if they gained some in the last turn
        if(experience >= 100) {
            experience -= 100;
            printf("You leveled up! You gain +1 defense.\n");
            defense += 1;
        }
    }
    
    return 0;
}