//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>

int main() {
    //Welcome message
    printf("Welcome to the Text-Based Adventure Game!\n");
    
    //Ask for player's name
    printf("What's your name?\n");
    char name[20];
    scanf("%s", name);
    
    //Introduction
    printf("Hello, %s! You find yourself in a dark forest.\n", name);
    printf("You see two paths ahead of you - one on the left and one on the right.\n");
    printf("Which one will you choose? (L/R)\n");
    
    //Get player's choice
    char choice;
    scanf(" %c", &choice);
    
    //Left path
    if(choice == 'L') {
        printf("You chose the left path.\n");
        printf("You walk for a while and come across a river.\n");
        printf("You can either try to swim across or search for a bridge.\n");
        printf("What will you do? (S/B)\n");
        
        scanf(" %c", &choice);
        
        if(choice == 'S') {
            //Swim across
            printf("You start to swim across the river.\n");
            printf("But the current is too strong and you are swept away!\n");
            printf("You wake up on the shore, alone and lost.\n");
            printf("Game Over.\n");
            
        } else {
            //Search for a bridge
            printf("You decide to search for a bridge and soon come across one.\n");
            printf("You cross the bridge and continue on your journey.\n");
            printf("You encounter a giant tree with a hollow trunk.\n");
            printf("Would you like to enter the trunk? (Y/N)\n");
            
            scanf(" %c", &choice);
            
            if(choice == 'Y') {
                //Enter the tree
                printf("You enter the hollow trunk of the tree.\n");
                printf("Inside, you find a hidden treasure trove!\n");
                printf("Congratulations! You Win!\n");
                
            } else {
                //Don't enter the tree
                printf("You decide not to enter the tree and continue on your journey.\n");
                printf("You eventually find your way out of the forest.\n");
                printf("Congratulations! You Win!\n");
                
            }
        }
    } else {
        //Right path
        printf("You chose the right path.\n");
        printf("You walk for a while and come across a clearing with a castle in the distance.\n");
        printf("You can either approach the castle or continue on your path.\n");
        printf("What will you do? (A/C)\n");
        
        scanf(" %c", &choice);
        
        if(choice == 'A') {
            //Approach the castle
            printf("You approach the castle and are greeted by the king.\n");
            printf("He offers you a job as a knight in his kingdom.\n");
            printf("Will you accept? (Y/N)\n");
            
            scanf(" %c", &choice);
            
            if(choice == 'Y') {
                //Accept the job
                printf("You accept the job and become a knight in the king's kingdom.\n");
                printf("Congratulations! You Win!\n");
                
            } else {
                //Decline the job
                printf("You decline the job offer and continue on your journey.\n");
                printf("You eventually find your way out of the forest.\n");
                printf("Congratulations! You Win!\n");
                
            }
        } else {
            //Continue on the path
            printf("You decide to continue on your path.\n");
            printf("You eventually find your way out of the forest.\n");
            printf("Congratulations! You Win!\n");
            
        }
    }
    
    return 0;
}