//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Traffic_Light {
    int green_time;
    int yellow_time;
    int red_time;
};

void run_traffic_light(struct Traffic_Light *tl) {
    printf("Starting traffic light sequence:\n");

    while(1) {
        printf("Green Light for %d seconds\n", tl->green_time);
        sleep(tl->green_time);

        printf("Yellow Light for %d seconds\n", tl->yellow_time);
        sleep(tl->yellow_time);

        printf("Red Light for %d seconds\n", tl->red_time);
        sleep(tl->red_time);
    }
}

int main() {
    struct Traffic_Light tl = {30, 5, 15};

    run_traffic_light(&tl);

    return 0;
}