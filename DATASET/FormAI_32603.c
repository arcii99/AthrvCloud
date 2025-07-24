//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: protected
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Enumeration for the traffic light colors
enum traffic_light_color {
    RED,
    YELLOW,
    GREEN
};

// Enumeration for the traffic light states
enum traffic_light_state {
    STOP,
    GET_READY,
    GO
};

// Structure for the traffic light
struct traffic_light {
    enum traffic_light_color color;
    enum traffic_light_state state;
};

int main() {
    struct traffic_light light;  // initialize the traffic light
    light.color = RED;  // start with the red color
    light.state = STOP;  // start in the stop state

    // set up a random seed for the delay function
    srand((unsigned)time(NULL));

    // loop through the different light states
    for (int i = 0; i < 10; i++) {
        switch (light.state) {
            case STOP:
                printf("STOP: RED\n");
                light.color = RED;
                light.state = GET_READY;
                break;
            case GET_READY:
                printf("GET READY: YELLOW\n");
                light.color = YELLOW;
                light.state = GO;
                break;
            case GO:
                printf("GO: GREEN\n");
                light.color = GREEN;
                light.state = STOP;
                break;
        }

        // vary the delay time depending on the state
        int delay = (light.state == GET_READY) ? 2 : 4;
        delay += rand() % 2;
        sleep(delay);
    }

    return 0;
}