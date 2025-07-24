//FormAI DATASET v1.0 Category: Smart home automation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Smart home devices
    int light1 = 0, light2 = 0, ac = 0, tv = 0;
    
    // Random time
    srand(time(NULL));
    int hour = rand() % 24;
    
    // Print current time
    printf("Welcome to Smart Home Automation!\n");
    printf("Current time: %02d:00\n\n", hour);
    
    // Turn on lights based on time
    if(hour >= 6 && hour <= 12) {
        printf("Good morning! Turning on light1...\n");
        light1 = 1;
    } else if(hour > 12 && hour <= 18) {
        printf("Good afternoon! Turning on light2...\n");
        light2 = 1;
    } else if(hour > 18 && hour <= 22) {
        printf("Good evening! Turning on both lights...\n");
        light1 = 1;
        light2 = 1;
    } else {
        printf("It's late! Turning off all lights...\n");
    }
    
    // Turn on AC if it's hot
    int temp = rand() % 40;
    printf("\nCurrent temperature: %d C\n", temp);
    if(temp > 30) {
        printf("It's hot! Turning on the AC...\n");
        ac = 1;
    }
    
    // Turn on TV if it's evening
    if(hour > 18 && hour <= 22) {
        printf("It's evening! Turning on the TV...\n");
        tv = 1;
    }
    
    // Print final status
    printf("\nSmart Home Automation Status:\n");
    printf("Light1: %d\n", light1);
    printf("Light2: %d\n", light2);
    printf("AC: %d\n", ac);
    printf("TV: %d\n", tv);
    
    return 0;
}