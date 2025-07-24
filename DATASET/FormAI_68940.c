//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Define enum for traffic light colors
typedef enum {
    RED,
    YELLOW,
    GREEN
} TrafficLightColor;

// Function to print current traffic light color
void print_color(TrafficLightColor color) {
    switch (color) {
        case RED:
            printf("\nRed Light\n");
            break;
        case YELLOW:
            printf("\nYellow Light\n");
            break;
        case GREEN:
            printf("\nGreen Light\n");
            break;
    }
}

// Function to simulate traffic light changes with delay
void change_light(TrafficLightColor* current_color) {
    switch (*current_color) {
        case RED:
            *current_color = GREEN;
            sleep(5);
            break;
        case YELLOW:
            *current_color = RED;
            sleep(2);
            break;
        case GREEN:
            *current_color = YELLOW;
            sleep(3);
            break;
    }
}

int main() {
    TrafficLightColor current_color = RED;
    bool is_running = true;

    printf("Starting Traffic Light Controller...\n");

    while (is_running) {
        print_color(current_color);
        change_light(&current_color);
    }

    printf("Stopping Traffic Light Controller...\n");

    return 0;
}