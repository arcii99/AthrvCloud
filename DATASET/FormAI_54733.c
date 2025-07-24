//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: active
// C Traffic Light Controller Example

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define RED    "\033[31m"
#define YELLOW "\033[33m"
#define GREEN  "\033[32m"
#define RESET  "\033[0m"

// Define Traffic Light State
typedef enum {
    RED_LIGHT,
    YELLOW_LIGHT,
    GREEN_LIGHT
} TrafficLightState;

// Define Traffic Light Struct
typedef struct {
    TrafficLightState state;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} TrafficLight;

TrafficLight tl;

// Function to Set Traffic Light State
void set_traffic_light_state(TrafficLightState state) {
    pthread_mutex_lock(&tl.lock);
    tl.state = state;
    pthread_cond_broadcast(&tl.cond);
    pthread_mutex_unlock(&tl.lock);
}

// Function to Get Traffic Light State
TrafficLightState get_traffic_light_state() {
    TrafficLightState state;
    pthread_mutex_lock(&tl.lock);
    state = tl.state;
    pthread_mutex_unlock(&tl.lock);
    return state;
}

// Function to Display Traffic Light State
void display_traffic_light() {
    TrafficLightState state = get_traffic_light_state();
    switch (state) {
        case RED_LIGHT:
            printf("%s\nRED Light%s\n", RED, RESET);
            printf("                  \n");
            printf("   ______________ \n");
            printf("  /              \\\n");
            printf(" /                \\\n");
            printf("|                  |\n");
            printf("|       %s*%s        |\n", RED, RESET);
            printf("|                  |\n");
            printf(" \\                /\n");
            printf("  \\______________/\n");
            printf("                  \n");
            break;
        case YELLOW_LIGHT:
            printf("%s\nYELLOW Light%s\n", YELLOW, RESET);
            printf("                  \n");
            printf("   ______________ \n");
            printf("  /              \\\n");
            printf(" /                \\\n");
            printf("|                  |\n");
            printf("|        %s*%s       |\n", YELLOW, RESET);
            printf("|                  |\n");
            printf(" \\                /\n");
            printf("  \\______________/\n");
            printf("                  \n");
            break;
        case GREEN_LIGHT:
            printf("%s\nGREEN Light%s\n", GREEN, RESET);
            printf("                  \n");
            printf("   ______________ \n");
            printf("  /              \\\n");
            printf(" /                \\\n");
            printf("|                  |\n");
            printf("|         %s*%s      |\n", GREEN, RESET);
            printf("|                  |\n");
            printf(" \\                /\n");
            printf("  \\______________/\n");
            printf("                  \n");
            break;
        default:
            break;
    }
}

// Function for Red Light State
void *red_light() {
    while(1) {
        set_traffic_light_state(RED_LIGHT);
        sleep(5);
    }
}

// Function for Yellow Light State
void *yellow_light() {
    while(1) {
        set_traffic_light_state(YELLOW_LIGHT);
        sleep(2);
    }
}

// Function for Green Light State
void *green_light() {
    while(1) {
        set_traffic_light_state(GREEN_LIGHT);
        sleep(5);
    }
}

// Main Function
int main() {
    printf("Traffic Light Controller Program\n");

    // Initialize Traffic Light State
    tl.state = RED_LIGHT;

    // Initialize Traffic Light Lock
    pthread_mutex_init(&tl.lock, NULL);

    // Initialize Traffic Light Condition Variable
    pthread_cond_init(&tl.cond, NULL);

    // Create Threads for Traffic Light States
    pthread_t red_light_thread, yellow_light_thread, green_light_thread;

    pthread_create(&red_light_thread, NULL, red_light, NULL);
    pthread_create(&yellow_light_thread, NULL, yellow_light, NULL);
    pthread_create(&green_light_thread, NULL, green_light, NULL);

    // Main Loop for Displaying Traffic Light State
    while(1) {
        display_traffic_light();
        usleep(500000);
    }

    // Cleanup
    pthread_join(red_light_thread, NULL);
    pthread_join(yellow_light_thread, NULL);
    pthread_join(green_light_thread, NULL);
    pthread_mutex_destroy(&tl.lock);
    pthread_cond_destroy(&tl.cond);

    return 0;
}