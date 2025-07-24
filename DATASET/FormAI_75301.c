//FormAI DATASET v1.0 Category: Smart home automation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int living_room = 0;    //initialize rooms to off
    int bedroom = 0;
    int kitchen = 0;
    int bathroom = 0;

    srand(time(NULL)); //randomize seed for the rand() function

    printf("Welcome to the Smart Home Automation System\n");

    while(1){   //loop to keep program running

        int option = rand() % 4 + 1;    //randomly pick a room to turn on or off

        switch(option){
            case 1:
                if(living_room == 0){
                    printf("Turning on the Living Room Light\n");
                    living_room = 1;
                }
                else{
                    printf("Turning off the Living Room Light\n");
                    living_room = 0;
                }
                break;
            case 2:
                if(bedroom == 0){
                    printf("Turning on the Bedroom Light\n");
                    bedroom = 1;
                }
                else{
                    printf("Turning off the Bedroom Light\n");
                    bedroom = 0;
                }
                break;
            case 3:
                if(kitchen == 0){
                    printf("Turning on the Kitchen Light\n");
                    kitchen = 1;
                }
                else{
                    printf("Turning off the Kitchen Light\n");
                    kitchen = 0;
                }
                break;
            case 4:
                if(bathroom == 0){
                    printf("Turning on the Bathroom Light\n");
                    bathroom = 1;
                }
                else{
                    printf("Turning off the Bathroom Light\n");
                    bathroom = 0;
                }
                break;
        }

        //random delay before the next room is turned on/off
        int delay = rand() % 10 + 1;
        printf("Pausing for %d seconds...\n\n", delay);
        sleep(delay);

    }

    return 0;
}