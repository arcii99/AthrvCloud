//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NS_G 5
#define EW_G 10
#define YELLOW 3

int ns_cars_waiting = 0;
int ew_cars_waiting = 0;
int ns_light = 1;
int ew_light = 0;
int ns_timer = NS_G;
int ew_timer = YELLOW;

void handle_ns_green() {
    printf("North-South light is GREEN\n");
    printf("East-West light is RED\n");
    while (ns_timer > 0) {
        if (ns_cars_waiting > 0) {
            printf("%d cars waiting in North-South direction\n", ns_cars_waiting);
            ns_cars_waiting--;
        }
        printf("Time remaining for green light: %d\n", ns_timer);
        ns_timer--;
        sleep(1);
    }
    ns_light = 0;
    ew_light = 1;
    ns_timer = YELLOW;
    ew_timer = EW_G;
}

void handle_ew_green() {
    printf("North-South light is RED\n");
    printf("East-West light is GREEN\n");
    while (ew_timer > 0) {
        if (ew_cars_waiting > 0) {
            printf("%d cars waiting in East-West direction\n", ew_cars_waiting);
            ew_cars_waiting--;
        }
        printf("Time remaining for green light: %d\n", ew_timer);
        ew_timer--;
        sleep(1);
    }
    ns_light = 1;
    ew_light = 0;
    ns_timer = NS_G;
    ew_timer = YELLOW;
}

void update_cars_waiting() {
    int num_cars = rand() % 6;
    if (rand() % 2 == 0) {
        ns_cars_waiting += num_cars;
    } else {
        ew_cars_waiting += num_cars;
    }
}

int main() {
    srand(time(NULL));
    printf("Starting traffic light controller...\n");
    while (1) {
        update_cars_waiting();
        if (ns_light) {
            handle_ns_green();
        } else {
            handle_ew_green();
        }
    }
    return 0;
}