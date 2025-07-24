//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OPTIONS 3

int main() {
    char player_name[MAX_INPUT_LENGTH];
    char player_input[MAX_INPUT_LENGTH];
    int player_choice = 0;
    int player_health = 100;
    int monster_health = 50;
    
    printf("Welcome to the minimalist adventure game!\n");
    printf("Please enter your name: ");
    fgets(player_name, MAX_INPUT_LENGTH, stdin);
    player_name[strcspn(player_name, "\n")] = '\0';
    printf("Hello, %s! Your adventure begins now!\n", player_name);
    
    while (player_health > 0 && monster_health > 0) {
        printf("What would you like to do?\n");
        printf("Enter 1 to attack the monster.\n");
        printf("Enter 2 to defend.\n");
        printf("Enter 3 to run away.\n");
        fgets(player_input, MAX_INPUT_LENGTH, stdin);
        player_choice = atoi(player_input);

        switch (player_choice) {
            case 1:
                printf("You attack the monster and deal 10 damage!\n");
                monster_health -= 10;
                break;
            case 2:
                printf("You defend yourself and take no damage.\n");
                break;
            case 3:
                printf("You attempt to run away but the monster catches you.\n");
                player_health -= 10;
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        if (monster_health > 0) {
            printf("The monster attacks back and deals 5 damage!\n");
            player_health -= 5;
        }
        
        printf("\nYour health: %d\n", player_health);
        printf("Monster health: %d\n", monster_health);
    }

    if (player_health > 0) {
        printf("\nCongratulations, %s! You have defeated the monster!\n", player_name);
    } else {
        printf("\nGame over, %s. The monster has defeated you.\n", player_name);
    }
    
    return 0;
}