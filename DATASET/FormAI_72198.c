//FormAI DATASET v1.0 Category: Smart home light control ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int lightStatus = 0; //off

    srand(time(0)); //seed for random value generation
    int ambientLight = rand() % 101; //generate a random ambient light value between 0-100

    //initial status message
    printf("Current status: Light is %s, Ambient light level is %d/100\n", (lightStatus == 0)?"off":"on", ambientLight);

    //menu loop
    while(1) {
        printf("\nMenu options:\n1. Toggle light status\n2. Check ambient light level\n3. Exit\n");
        int option;
        scanf("%d", &option);

        if(option == 1) {
            //toggle light status
            lightStatus = !lightStatus;
            printf("Light is now %s\n", (lightStatus == 0)?"off":"on");

            //check ambient light level and adjust accordingly
            ambientLight = rand() % 101;
            if(lightStatus == 0 && ambientLight > 50) {
                //turn on lights if ambient light is low
                printf("Ambient light level is low, turning on lights.\n");
                lightStatus = 1;
            } else if(lightStatus == 1 && ambientLight < 30) {
                //turn off lights if ambient light is high
                printf("Ambient light level is high, turning off lights.\n");
                lightStatus = 0;
            }
        } else if(option == 2) {
            //check ambient light level
            printf("Ambient light level is %d/100\n", ambientLight);
        } else if(option == 3) {
            //exit program
            printf("Exiting program.\n");
            break;
        } else {
            //invalid option
            printf("Invalid option, please enter 1, 2, or 3.\n");
        }
    }
    return 0;
}