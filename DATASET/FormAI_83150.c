//FormAI DATASET v1.0 Category: Smart home light control ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

//function to turn on the lights
void turn_on_lights(){
    printf("Lights are turned ON\n");
}

//function to turn off the lights
void turn_off_lights(){
    printf("Lights are turned OFF\n");
}

int main(){
    int choice, exit_choice;
    printf("\nWelcome to Smart Home Light Control System\n");
    printf("------------------------------------------------\n");
    while(1){
        printf("\nWhat would you like to do?\n");
        printf("1. Turn ON the lights\n");
        printf("2. Turn OFF the lights\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                turn_on_lights();
                break;
            case 2:
                turn_off_lights();
                break;
            case 3:
                printf("\nAre you sure you want to exit?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d", &exit_choice);
                if(exit_choice == 1){
                    printf("\nExiting the Smart Home Light Control System..\n");
                    exit(0);
                }
                else{
                    break;
                }
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}