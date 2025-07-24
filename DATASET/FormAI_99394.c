//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

void lightController(int currentLight, int time){
    printf("\n\n");
    switch(currentLight){
        case RED:
            printf("RED Light: ON\n");
            printf("YELLOW Light: OFF\n");
            printf("GREEN Light: OFF\n");
            printf("==================================\n");
            printf("|                                  |\n");
            printf("|          STAY STOPPED            |\n");
            printf("|                                  |\n");
            printf("==================================\n");
            sleep(time);
            lightController(YELLOW, 2);
            break;
        case YELLOW:
            printf("RED Light: OFF\n");
            printf("YELLOW Light: ON\n");
            printf("GREEN Light: OFF\n");
            printf("==================================\n");
            printf("|                                  |\n");
            printf("|         PREPARE TO START          |\n");
            printf("|                                  |\n");
            printf("==================================\n");
            sleep(time);
            lightController(GREEN, 5);
            break;
        case GREEN:
            printf("RED Light: OFF\n");
            printf("YELLOW Light: OFF\n");
            printf("GREEN Light: ON\n");
            printf("==================================\n");
            printf("|                                  |\n");
            printf("|           GO GO GO!!!            |\n");
            printf("|                                  |\n");
            printf("==================================\n");
            sleep(time);
            lightController(YELLOW, 2);
            break;
        default:
            printf("Error! Invalid light.");
            exit(0);
    }
}

int main(){
    lightController(RED, 10);
    return 0;
}