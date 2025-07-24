//FormAI DATASET v1.0 Category: Smart home automation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_daytime(int time) {
    return (time >= 6 && time < 21);
}

int main() {
    int time = 8; // current time
    bool is_home = true; // is anyone currently in the castle?

    // sensors
    bool door_sensor = false;
    bool window_sensor = true;

    // devices
    bool lights = false;
    bool fireplace = false;
    bool drawbridge = true;
    bool gate = true;

    // main loop
    while (true) {
        // check if it's daytime
        if (is_daytime(time)) {
            // turn off lights and fireplace during the day
            lights = false;
            fireplace = false;
        } else {
            // turn on lights and fireplace at night
            lights = true;
            fireplace = true;
        }

        // check if anyone is home
        if (!is_home) {
            // close drawbridge and gate when no one is home
            drawbridge = false;
            gate = false;
        } else {
            // open drawbridge and gate when someone is home
            drawbridge = true;
            gate = true;
        }

        // check sensors
        if (door_sensor || window_sensor) {
            // turn on lights and fireplace when someone enters
            lights = true;
            fireplace = true;
        }

        // update devices
        // ...

        // output status
        printf("Time: %d, Lights: %d, Fireplace: %d, Drawbridge: %d, Gate: %d\n", time, lights, fireplace, drawbridge, gate);
        
        // increment time
        time = (time + 1) % 24;
    }

    return 0;
}