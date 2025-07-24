//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro(){
    printf("You are a knight on a quest to save the kingdom from an alien invasion.\n");
    printf("You have been sent to space to defeat the aliens and save the kingdom.\n");
    printf("You enter the spaceship and prepare for battle.\n\n");
}

void generateAlien(int* health, int* damage){
    //generate random alien health and damage values
    *health = rand() % 51 + 50;
    *damage = rand() % 11 + 15;
}

void battle(int* playerHealth, int* playerDamage){
    int alienHealth, alienDamage;
    generateAlien(&alienHealth, &alienDamage);

    while(*playerHealth > 0 && alienHealth > 0){
        //player attacks alien
        printf("You attack the alien for %d damage.\n", *playerDamage);
        alienHealth -= *playerDamage;
        if(alienHealth <= 0){
            printf("You defeat the alien!\n");
            break;
        }

        //alien attacks player
        printf("The alien attacks you for %d damage.\n", alienDamage);
        *playerHealth -= alienDamage;
        if(*playerHealth <= 0){
            printf("You have been defeated by the alien.\n");
            break;
        }
    }
}

int main(){
    srand(time(NULL)); //seed the random number generator

    int playerHealth = 100; //starting health for player
    int playerDamage = 20; //damage output for player

    printIntro();

    //first battle
    printf("You encounter an alien!\n");
    battle(&playerHealth, &playerDamage);

    if(playerHealth > 0){
        //second battle, player gets stronger
        printf("You find a secret room and find a sword that increases your damage output.\n");
        playerDamage += 10;
        printf("You continue your journey and encounter another alien.\n");
        battle(&playerHealth, &playerDamage);

        if(playerHealth > 0){
            //third battle, player gets even stronger
            printf("The final boss awaits!\n");
            playerDamage += 20;
            battle(&playerHealth, &playerDamage);

            if(playerHealth > 0){
                printf("Congratulations! You have saved the kingdom and defeated the alien invasion.\n");
            }
            else{
                printf("You have been defeated by the final boss.\n");
            }
        }
        else{
            printf("You have been defeated by the second alien.\n");
        }
    }
    else{
        printf("You have been defeated by the first alien.\n");
    }

    return 0;
}