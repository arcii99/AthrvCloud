//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char name[20], choice[10];
    int lover_choice, money = 0;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What is your name?\n");
    scanf("%s", name);

    printf("\n%s, you wake up in a strange room. You don't remember how you got here.\n", name);
    printf("As you try to get up, you notice a note on the dresser that reads:\n");
    printf("'Welcome to the game. You have two options: Option A - Find your way out of this room or Option B - Stay in this room forever.'\n");
    printf("What would you like to do? (A/B)\n");
    scanf("%s", choice);

    if(strcmp(choice, "A")==0){
        printf("\n%s, you start looking for a way out. You find a locked door and a window that is too high to reach.\n", name);
        printf("You hear a voice coming from outside. It's your lover shouting for you. They are outside the window and have the key to the door.\n");
        printf("What would you like to do? \n");
        printf("1. Wait for them to unlock the door\n");
        printf("2. Try to break the window\n");
        scanf("%d", &lover_choice);

        if(lover_choice == 1){
            printf("\nYou successfully escape the room with the help of your lover. Congratulations, you've won the game!\n");
            money += 100;
        }
        else if(lover_choice == 2){
            printf("\nYou try to break the window, but it's too strong. You'll have to wait for your lover to help you. Game over.\n");
        }
        else{
            printf("\nInvalid choice. You lose the game!\n");
        }
    }
    else if(strcmp(choice, "B")==0){
        printf("\n%s, you've decided to stay in the room forever. You'll never know what could have been. Game over.\n", name);
    }
    else{
        printf("\nInvalid choice. You lose the game!\n");
    }

    printf("\n%s, you've won %d dollars. Thanks for playing!\n", name, money);

    return 0;
}