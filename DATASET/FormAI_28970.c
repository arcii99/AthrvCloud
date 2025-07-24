//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: retro
#include <stdio.h>
#include <time.h>

#define RED_LIGHT_TIME 5
#define YELLOW_LIGHT_TIME 2
#define GREEN_LIGHT_TIME 10

enum traffic_light_state {
    RED,
    YELLOW,
    GREEN
};

int main() {
    enum traffic_light_state state = RED;

    printf("Traffic Light Controller - Retro Edition\n\n");

    while (1) {
        int i;
        time_t start_time = time(NULL);

        printf("[RED]\n");

        for (i = 0; i < RED_LIGHT_TIME; i++) {
            printf("%d seconds left...\n", RED_LIGHT_TIME - i);
            sleep(1);
        }

        printf("[GREEN]\n");

        state = GREEN;

        for (i = 0; i < GREEN_LIGHT_TIME; i++) {
            printf("%d seconds left...\n", GREEN_LIGHT_TIME - i);
            sleep(1);
        }

        printf("[YELLOW]\n");

        state = YELLOW;

        for (i = 0; i < YELLOW_LIGHT_TIME; i++) {
            printf("%d seconds left...\n", YELLOW_LIGHT_TIME - i);
            sleep(1);
        }

        state = RED;
    }

    return 0;
}