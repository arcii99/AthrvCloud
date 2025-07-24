//FormAI DATASET v1.0 Category: Smart home light control ; Style: futuristic
#include<stdio.h>
#include<stdbool.h>

/* Function to turn on the lights */
void turn_on_lights(bool *lights){
    *lights = true;
    printf("Lights are turned on!\n");
}

/* Function to turn off the lights */
void turn_off_lights(bool *lights){
    *lights = false;
    printf("Lights are turned off!\n");
}

int main(){
    bool lights = false; // Initializing the lights to be off
    
    printf("Hi! Welcome to the Future Smart Home!\n");
    printf("Today we will be demonstrating the light control feature!\n\n");

    char option;
    
    while(true){
        printf("Enter 'o' to turn on the lights, 'f' to turn off the lights and 'q' to quit the program: ");
        scanf(" %c", &option);
        printf("\n");

        if(option == 'o'){
            turn_on_lights(&lights);
        }
        else if(option == 'f'){
            turn_off_lights(&lights);
        }
        else if(option == 'q'){
            printf("Thank you for testing the light control feature of the Future Smart Home!\n");
            break;
        }
        else{
            printf("Invalid option! Please try again.\n\n");
        }
    }
    
    return 0;
}