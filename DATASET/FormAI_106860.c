//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define GREEN_LIGHT 0
#define YELLOW_LIGHT 1
#define RED_LIGHT 2

typedef struct{
    bool green;
    bool yellow;
    bool red;
} Light;

void setLight(Light *light, int colorIndex){
    light->green = false;
    light->yellow = false;
    light->red = false;
    switch(colorIndex){
        case GREEN_LIGHT:
            light->green = true;
            break;
        case YELLOW_LIGHT:
            light->yellow = true;
            break;
        case RED_LIGHT:
            light->red = true;
            break;
    }
}

void displayStatus(Light light){
    printf("Light Status:\n");
    printf("------------------------------\n");
    printf("%s\n", light.green ? "Green light is on" : "Green light is off");
    printf("%s\n", light.yellow ? "Yellow light is on" : "Yellow light is off");
    printf("%s\n", light.red ? "Red light is on" : "Red light is off");
}

int main(){
    Light light;
    int count = 1;
    while(count <= 10){
        printf("\nCycle: %d\n", count);
        printf("------------------------------\n");
        setLight(&light, GREEN_LIGHT);
        displayStatus(light);
        printf("Waiting for 10 seconds\n\n");
        sleep(10);
        setLight(&light, YELLOW_LIGHT);
        displayStatus(light);
        printf("Waiting for 5 seconds\n\n");
        sleep(5);
        setLight(&light, RED_LIGHT);
        displayStatus(light);
        printf("Waiting for 15 seconds\n\n");
        sleep(15);
        count++;
    }
    return 0;
}