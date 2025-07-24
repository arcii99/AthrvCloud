//FormAI DATASET v1.0 Category: Smart home light control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Function to control the lights based on a schedule */
void controlLights(int currentHour, int currentMinute) {
    // 5 PM to 10 PM: Turn on lights
    if((currentHour == 17 && currentMinute >= 0) || (currentHour >= 18 && currentHour <= 21) || (currentHour == 22 && currentMinute == 0)) {
        printf("Turning on lights.\n");
    }

    // 10 PM to 7 AM: Dim the lights
    else if((currentHour == 22 && currentMinute > 0) || (currentHour >= 23 && currentHour <= 5) || (currentHour == 6 && currentMinute == 0)) {
        printf("Dimming the lights.\n");
    }

    // 7 AM to 9 AM: Turn on lights
    else if((currentHour == 6 && currentMinute > 0) || (currentHour >= 7 && currentHour <= 8) || (currentHour == 9 && currentMinute == 0)) {
        printf("Turning on lights.\n");
    }

    // 9 AM to 5 PM: Turn off lights
    else {
        printf("Turning off lights.\n");
    }
}


int main() {
    // Get current time
    time_t currentTime;
    struct tm *localTime;

    // Get current time
    currentTime = time(NULL);

    // Convert current time to local time
    localTime = localtime(&currentTime);

    // Get current hour and minute
    int currentHour = localTime->tm_hour;
    int currentMinute = localTime->tm_min;

    // Control the lights based on the current time
    controlLights(currentHour, currentMinute);

    return 0;
}