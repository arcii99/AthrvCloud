//FormAI DATASET v1.0 Category: Smart home automation ; Style: Donald Knuth
#include<stdio.h>

// function to turn on/off lights
void toggleLight(int state){
    if(state == 0)
        printf("Lights turned OFF.\n");
    else
        printf("Lights turned ON.\n");
}

// function to turn on/off fan
void toggleFan(int state){
    if(state == 0)
        printf("Fan turned OFF.\n");
    else
        printf("Fan turned ON.\n");
}

int main(){
    // assuming initially everything is off
    int lightsState = 0;
    int fanState = 0;

    // turn on the lights
    lightsState = 1;
    toggleLight(lightsState);

    // turn on the fan
    fanState = 1;
    toggleFan(fanState);

    // wait for some time
    printf("Waiting for 10 seconds...\n");
    sleep(10);

    // turn off the fan
    fanState = 0;
    toggleFan(fanState);

    // turn off the lights
    lightsState = 0;
    toggleLight(lightsState);

    return 0;
}