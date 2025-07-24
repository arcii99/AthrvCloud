//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0)); //to generate random numbers
    
    int health = 100; //starting health of player
    int enemy_health = 80; //starting health of enemy
    int choice; //to store user's choice of action
    int enemy_choice; //to store enemy's choice of action
    
    printf("\n\nWelcome to Text Adventure Game!\n");
    printf("Your mission is to defeat the enemy and save the world.\n");
    printf("You have 100 health points. Good luck!\n\n\n");
    
    printf("Press any key to continue...\n");
    getchar(); //to wait for user to press any key to continue
    
    printf("\n\nYou are walking in a dark forest. Suddenly, an enemy appears!\n");
    printf("He has 80 health points and looks very dangerous.\n");
    
    while(health > 0 && enemy_health > 0){ //game loop
        
        printf("\n\nYour turn:\n");
        printf("1. Attack\n");
        printf("2. Defend\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("\nYou attack the enemy!\n");
                int damage = 10 + (rand() % 11); //generate random damage between 10 and 20
                printf("You dealt %d damage to the enemy.\n", damage);
                enemy_health -= damage;
                break;
            case 2:
                printf("\nYou defend yourself!\n");
                printf("The enemy's attack is weakened.\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
        
        if(enemy_health > 0){ //enemy turn only if he is alive
            printf("\n\nEnemy's turn:\n");
            enemy_choice = rand() % 2 + 1; //generate random choice between 1 and 2
            
            switch(enemy_choice){
                case 1:
                    printf("\nThe enemy attacks you!\n");
                    int enemy_damage = 5 + (rand() % 11); //generate random damage between 5 and 15
                    printf("You lost %d health points.\n", enemy_damage);
                    health -= enemy_damage;
                    break;
                case 2:
                    printf("\nThe enemy defends himself!\n");
                    printf("Your attack is weakened.\n");
                    break;
            }
        }
        
        printf("\n\nYour health: %d\n", health);
        printf("Enemy's health: %d\n", enemy_health);
        
    }
    
    if(health > 0){
        printf("\n\nCongratulations! You defeated the enemy and saved the world!\n");
    }
    else{
        printf("\n\nGame over! You lost all your health points.\n");
    }
    
    return 0;
}