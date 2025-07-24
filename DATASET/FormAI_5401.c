//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include<stdio.h>

int main(){
    printf("\nWelcome to the Land of Knuthia!\n");
    printf("What do you want to do?\nOptions: explore, rest, exit\n");
    char option[15];
    scanf("%s", option);
    if(strcmp(option, "explore") == 0){
        printf("\nYou enter the forest and notice a bear approaching you.\n");
        printf("Options: fight, hide\n");
        char decision[10];
        scanf("%s", decision);
        if(strcmp(decision, "fight") == 0){
            printf("\nYou approach the bear and realize too late that it was a bad idea.\n");
            printf("The bear kills you! Game over.\n");
        }
        else if(strcmp(decision, "hide") == 0){
            printf("\nYou hide behind a tree and the bear passes by.\n");
            printf("You continue exploring the forest and find a treasure chest!\n");
            printf("Options: open, leave\n");
            char treasure[10];
            scanf("%s", treasure);
            if(strcmp(treasure, "open") == 0){
                printf("\nYou open the chest and find a magical sword!\n");
                printf("You equip the sword and continue your adventure.\n");
                printf("Congratulations! You won the game!\n");
            }
            else if(strcmp(treasure, "leave") == 0){
                printf("\nYou leave the chest and continue exploring the forest.\n");
                printf("You encounter a group of goblins and are defeated. Game over.\n");
            }
        }
    }
    else if(strcmp(option, "rest") == 0){
        printf("\nYou find a comfortable spot and take a nap.\n");
        printf("You wake up refreshed and ready to continue your adventure!\n");
        main();
    }
    else if(strcmp(option, "exit") == 0){
        printf("\nGoodbye! Thanks for playing!\n");
        return 0;
    }
    else{
        printf("\nInvalid option. Please try again.\n");
        main();
    }
    return 0;
}