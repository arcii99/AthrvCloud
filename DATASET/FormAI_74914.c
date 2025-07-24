//FormAI DATASET v1.0 Category: Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL)); //initializes the random number generator with a unique seed
    int health = 100, enemy_health = 100, player_attack, enemy_attack;
    int player_wins = 0, enemy_wins = 0;
    int round = 1;

    printf("Welcome to Medieval Combat!\n\n");

    while(health > 0 && enemy_health > 0){
        printf("Round %d\n", round);
        printf("Your Health: %d\nEnemy Health: %d\n", health, enemy_health);

        //player turn
        printf("\nYour turn to attack!\n");
        player_attack = (rand() % 20) + 10; //generates a random attack number between 10 and 30
        printf("You dealt %d damage to the enemy!\n", player_attack);
        enemy_health -= player_attack;

        //enemy turn
        if(enemy_health > 0){
            printf("\nEnemy's turn to attack!\n");
            enemy_attack = (rand() % 20) + 5; //generates a random attack number between 5 and 25
            printf("The enemy dealt %d damage to you!\n", enemy_attack);
            health -= enemy_attack;
        }

        round++;

        //check if either player or enemy has won
        if(enemy_health <= 0){
            player_wins++;
            printf("\nYou have killed the enemy in combat!\n");
            printf("Player wins: %d\nEnemy wins: %d\n", player_wins, enemy_wins);
            printf("Press enter to continue.\n");
            getchar(); //waits for user to press enter before continuing to next round
            enemy_health = 100; //resets enemy health for next round
        } else if(health <= 0){
            enemy_wins++;
            printf("\nYou have been defeated in combat!\n");
            printf("Player wins: %d\nEnemy wins: %d\n", player_wins, enemy_wins);
            printf("Press enter to exit game.\n");
            getchar(); //waits for user to press enter before exiting game
        }
    }

    return 0;
}