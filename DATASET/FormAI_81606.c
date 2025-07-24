//FormAI DATASET v1.0 Category: Smart home automation ; Style: random
#include <stdio.h>
#include <stdlib.h>

void turnOnLight(int roomNumber){
    printf("Light in room %d turned on.\n", roomNumber);
}

void turnOffLight(int roomNumber){
    printf("Light in room %d turned off.\n", roomNumber);    
}

void adjustTemperature(int temperature){
    printf("Temperature adjusted to %d degrees.\n", temperature);
}

void adjustBlinds(int blindsPercentage){
    printf("%d%% of blinds lowered.\n", blindsPercentage);   
}

int main(){
    int currentTemperature = 25;
    int desiredTemperature = 22;
    int livingRoomBrightness = 75;
    int kitchenBrightness = 50;
    int blindsPercentage = 25;
    
    if(currentTemperature > desiredTemperature){
        adjustTemperature(desiredTemperature);
    }
    
    if(livingRoomBrightness < 60){
        turnOnLight(1);
    }
    else{
        turnOffLight(1);
    }
    
    if(kitchenBrightness < 60){
        turnOnLight(2);
    }
    else{
        turnOffLight(2);
    }
    
    if(blindsPercentage < 50){
        adjustBlinds(50);
    }
    else{
        adjustBlinds(0);
    }
    
    return 0;
}