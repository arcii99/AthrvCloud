//FormAI DATASET v1.0 Category: Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize the random number generator
    
    int player_health = 100;
    int enemy_health = 100;
    int player_damage, enemy_damage;
    int turn_counter = 1;
    
    printf("Welcome to the futuristic battle game!\n");
    
    while (player_health > 0 && enemy_health > 0) {
        printf("\nTURN %d:\n", turn_counter);
        printf("Player health: %d\n", player_health);
        printf("Enemy health: %d\n", enemy_health);
        
        player_damage = rand() % 21 + 10; // Player can deal between 10-30 damage
        enemy_damage = rand() % 31 + 5; // Enemy can deal between 5-35 damage
        
        printf("Player attacks the enemy and deals %d damage.\n", player_damage);
        enemy_health -= player_damage;
        
        if (enemy_health <= 0) break; // If the enemy dies, end the game
        
        printf("Enemy attacks the player and deals %d damage.\n", enemy_damage);
        player_health -= enemy_damage;
        
        turn_counter++;
    }
    
    if (player_health <= 0) {
        printf("\nYou have died. Game over.\n");
    } else {
        printf("\nCongratulations! You have defeated the enemy. You win!\n");
    }
    
    return 0;
}