//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int option, x=0, y=0, dragon_health=10, player_health=10, sword=0;
    printf("Welcome to the Mathematical Adventure Game!\n");

    while(player_health>0 && dragon_health>0){
        printf("\nCurrent position: (%d,%d)\n",x,y);
        printf("You see a dragon ahead!\n");

        printf("What do you want to do?\n");
        printf("1. Fight dragon\n");
        printf("2. Run away\n");
        printf("3. Pick up sword\n");
        scanf("%d",&option);

        switch(option){
            case 1:
                if(sword==0){
                    printf("You don't have a sword to fight with. You take a hit and run away!\n");
                    player_health -= 1;
                }
                else{
                    printf("You use your sword to attack the dragon! It loses 2 health points.\n");
                    dragon_health -= 2;
                }
                break;
            case 2:
                printf("You run away! The dragon gains 1 health point.\n");
                dragon_health += 1;
                x = rand()%10;
                y = rand()%10;
                break;
            case 3:
                printf("You pick up a sword lying on the ground.\n");
                sword = 1;
                break;
            default:
                printf("Invalid option. You lose a health point.\n");
                player_health -= 1;
                break;
        }

        //Mathematical calculations
        double distance = sqrt(pow(x-5,2)+pow(y-5,2));
        player_health -= distance;
        dragon_health -= floor(distance/3);

        printf("Your health: %d, Dragon health: %d\n", player_health, dragon_health);
    }

    if(player_health>0)
        printf("Congratulations! You defeated the dragon and won the game!\n");

    if(dragon_health>0)
        printf("Game over! The dragon defeated you.\n");

    return 0;
}