//FormAI DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int light1 = 0, light2 = 0, light3 = 0;

    printf("Welcome to Smart Home Light Control\n");
    printf("----------------------------------\n");

    while (1) {
        printf("\nCurrent Light Status:\n");
        printf("Light 1: %d\n", light1);
        printf("Light 2: %d\n", light2);
        printf("Light 3: %d\n", light3);

        printf("\nEnter Light Number and Command (1/2/3 on/off/toggle): ");
        int lightNum;
        char cmd[8];

        scanf("%d %s", &lightNum, &cmd);

        if (lightNum == 1) {
            if (strcmp(cmd, "on") == 0) {
                light1 = 1;
                printf("Light 1 is now ON!\n");
            } else if (strcmp(cmd, "off") == 0) {
                light1 = 0;
                printf("Light 1 is now OFF!\n");
            } else if (strcmp(cmd, "toggle") == 0) {
                light1 = !light1;
                printf("Light 1 is now %s!\n", (light1) ? "ON" : "OFF");
            } else {
                printf("Invalid command!\n");
            }
        } else if (lightNum == 2){
           //same as above for light 2
        } else if (lightNum == 3){
           //same as above for light 3
        } else {
            printf("Invalid Light Number!\n");
        }
    }

    return 0;
}