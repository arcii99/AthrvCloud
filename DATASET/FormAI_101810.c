//FormAI DATASET v1.0 Category: Smart home light control ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int time_hour, time_minute;
    int light_status = 0; // 0 for Off and 1 for On
    int presence = 0; // 0 for absence and 1 for presence
    int lux = 0; // Stores the value of Lux
    int max_lux = 500; // Maximum Lux value for turning On the lights
    int min_lux = 50; // Minimum Lux value for turning Off the lights
    int motion_timer = 30; // Timer for turning Off the lights after motion is not detected for this many seconds

    srand(time(0));

    // Generate random Lux value
    lux = (rand() % (max_lux - min_lux + 1)) + min_lux;

    // Check if lights should turn On automatically due to low Lux value
    if(lux < max_lux/2){
        light_status = 1;
    }

    // Loop to simulate presence and absence of people in the house
    for(int i = 0; i < 24; i++){
        // Generate random presence value for each hour of the day
        presence = rand() % 2;

        // Check if someone is present in the house
        if(presence == 1){
            // Generate random time for the person being present in the house
            time_hour = rand() % 24;
            time_minute = rand() % 60;

            // Check if it is nighttime for turning On the lights automatically
            if(time_hour >= 18 || time_hour < 6){
                light_status = 1;
            }

            // Loop to simulate motion detection in the house
            for(int j = 0; j < 60; j++){
                // Generate random motion detection value for each minute of presence
                int motion = rand() % 2;

                // Check if motion is detected
                if(motion == 1){
                    light_status = 1;
                    // Reset motion timer
                    motion_timer = 30;
                }else{
                    // Decrease motion timer if no motion is detected
                    motion_timer--;
                    if(motion_timer <= 0){
                        light_status = 0;
                    }
                }
                // Wait for 1 second
                sleep(1);
            }
            // Turn off the lights when leaving the house
            light_status = 0;
        }
    }
    return 0;
}