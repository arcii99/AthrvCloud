//FormAI DATASET v1.0 Category: Smart home automation ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool isHome = true;
    bool isNight = true;
    bool isBedtime = false;
    bool isMotionDetected = false;
    bool isLightOn = false;
    
    while (true) {
        if (isHome) {
            if (isNight) {
                if (!isBedtime) {
                    if (isMotionDetected) {
                        isLightOn = true;
                        printf("Motion detected. Turning on lights.\n");
                    }
                }
            }
        }
        isMotionDetected = false; // Reset motion detected flag
    }

    return 0;
}