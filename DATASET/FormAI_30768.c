//FormAI DATASET v1.0 Category: Smart home light control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define variables
    int lightStatus = 0;
    int temperature = 25;
    int humidity = 50;
    int motion = 0;
    
    // Simulate temperature and humidity readings
    srand(time(NULL));
    temperature = rand() % 10 + 20;
    humidity = rand() % 10 + 40;
    
    // Simulate motion detection
    motion = rand() % 2 == 0 ? 1 : 0;
    
    // Turn on lights if it's dark or if there is motion
    if (temperature < 22 || humidity > 60 || !lightStatus || motion) { 
        lightStatus = 1;
        printf("Turning on the lights.\n");
    }
    
    // Turn off lights if it's bright and there is no motion
    else if (temperature > 25 && humidity < 50 && lightStatus && !motion) {
        lightStatus = 0;
        printf("Turning off the lights.\n");
    }
    
    // Print current status
    printf("Current temperature: %d\n", temperature);
    printf("Current humidity: %d\n", humidity);
    printf("Current light status: %s\n", lightStatus ? "ON" : "OFF");
    printf("Motion detected: %s\n", motion ? "YES" : "NO");
    
    return 0;
}