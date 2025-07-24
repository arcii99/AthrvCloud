//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum TrafficSignal {RED, YELLOW, GREEN};

typedef struct {
    enum TrafficSignal color;
    int duration; 
} TrafficLight;

int main(void) {
    TrafficLight trafficLights[3];
    trafficLights[RED].color = RED;
    trafficLights[RED].duration = 10;
    trafficLights[YELLOW].color = YELLOW;
    trafficLights[YELLOW].duration = 2;
    trafficLights[GREEN].color = GREEN;
    trafficLights[GREEN].duration = 15;
    
    int countDown = trafficLights[trafficLights[RED].color].duration;
    printf("Starting countdown...\n\n");
    
    while(countDown > 0) {
        printf("%d seconds remaining...\n", countDown);
        sleep(1);
        countDown--;
    }
    
    printf("\n\nChanging traffic light to YELLOW...\n\n");
    countDown = trafficLights[trafficLights[YELLOW].color].duration;
    
    while(countDown > 0) {
        printf("%d seconds remaining...\n", countDown);
        sleep(1);
        countDown--;
    }
    
    printf("\n\nChanging traffic light to GREEN...\n\n");
    countDown = trafficLights[trafficLights[GREEN].color].duration;
    
    while(countDown > 0) {
        printf("%d seconds remaining...\n", countDown);
        sleep(1);
        countDown--;
    }
    
    printf("\n\nChanging traffic light to RED...\n\n");
    countDown = trafficLights[trafficLights[RED].color].duration;
    
    while(countDown > 0) {
        printf("%d seconds remaining...\n", countDown);
        sleep(1);
        countDown--;
    }
    
    printf("\n\nTraffic light circuit complete.\n");
    
    return 0;
}