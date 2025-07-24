//FormAI DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

int main(){

    int ammo = 0; //initial ammo count
    int distance = 10; //initial distance to target

    //random chance of an error occurring
    int error_chance = rand() % 10;
    
    //if error chance is above 5, an error occurs
    if(error_chance > 5){
        printf("Error: No ammo left!\n");
        exit(-1); //exit program with error code -1
    }
    
    //if error chance is below 5, execute code normally
    else{
        //decrement ammo count as shots are fired
        for(int i=0; i<10; i++){
            ammo++;
            printf("Firing shot %d\n", i+1);

            //random chance of an error occurring
            error_chance = rand() % 10;

            //if error chance is above 7, an error occurs
            if(error_chance > 7){
                printf("Error: Weapon malfunction\n");
                exit(-1); //exit program with error code -1
            }

            //if error chance is between 5 and 7, miss target
            else if(error_chance > 5 && error_chance <= 7){
                printf("Missed target at distance %d meters\n", distance);
            }

            //if error chance is below 5, hit target
            else{
                printf("Target hit at distance %d meters\n", distance);
                distance -= 1; //decrement distance as target is hit
            }

            //if no ammo left, exit program with error code -1
            if(ammo == 0){
                printf("Error: No ammo left!\n");
                exit(-1);
            }
        }

        printf("Ammo left: %d\n", ammo);
        printf("Distance to target: %d\n", distance);
        printf("Mission success!\n");
        return 0; //exit program with success code 0
    }
}