//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int playerHealth = 100;
int enemyHealth = 100;
int playerAttack = 10;
int enemyAttack = 15;

void introduction(){
    printf("Welcome to the Dark Cave! You are a brave warrior seeking adventure and treasure!\n\n");
    printf("You can move by typing 'north', 'south', 'east' or 'west'.\n\n");
    printf("If you want to exit the game, type 'quit'.\n\n");
}

void gameOver(){
    printf("You died! Game over.\n");
    exit(0);
}

void win(){
    printf("Congratulations! You defeated the monster and found the treasure!\n");
    exit(0);
}

void fight(){
    char action[10];

    while (playerHealth>0 && enemyHealth>0){
        printf("Player: %d\t Enemy: %d\n", playerHealth, enemyHealth);
        printf("What's your next move? (attack/heal): ");
        fgets(action, sizeof(action), stdin);
        action[strcspn(action, "\r\n")] = 0;  //remove newline character
        
        if (strcmp(action, "attack") == 0){
            enemyHealth -= playerAttack;
            printf("You dealt %d damage!\n", playerAttack);
            if (enemyHealth <= 0){
                win();
            }
            
            playerHealth -= enemyAttack;
            printf("The enemy dealt %d damage!\n", enemyAttack);
            if (playerHealth <= 0){
                gameOver();
            }
        }
        else if (strcmp(action, "heal") == 0){
            playerHealth += 20;
            if (playerHealth > 100){
                playerHealth = 100;
            }
            
            playerHealth -= enemyAttack;
            printf("You healed yourself!\n");
            printf("The enemy dealt %d damage!\n", enemyAttack);
            if (playerHealth <= 0){
                gameOver();
            }
        }
        else{
            printf("Invalid command.\n");
        }
    }
}

int main() {
    char direction[10];

    introduction();
    
    while (1){
        printf("Which direction do you want to go? ");
        fgets(direction, sizeof(direction), stdin);
        direction[strcspn(direction, "\r\n")] = 0;  //remove newline character
        
        if (strcmp(direction, "north") == 0){
            printf("You found a monster!\n");
            fight();
        }
        else if (strcmp(direction, "south") == 0){
            printf("You found a treasure!\n");
            win();
        }
        else if (strcmp(direction, "east") == 0){
            printf("You found a dead end.\n");
        }
        else if (strcmp(direction, "west") == 0){
            printf("You found a trap!\n");
            printf("You lost 50 health in the trap!\n");
            playerHealth -= 50;
            if (playerHealth <= 0){
                gameOver();
            }
        }
        else if (strcmp(direction, "quit") == 0){
            exit(0);
        }
        else{
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}