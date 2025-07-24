//FormAI DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_LIGHTS 4

bool lights_on[NUM_LIGHTS] = {false, false, false, false};

void print_menu() {
    printf("Select a light to control:\n");
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("%d. Light %d\n", i+1, i+1);
    }
    printf("%d. Quit\n", NUM_LIGHTS+1);
}

void print_status() {
    printf("Light status:\n");
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("Light %d: %s\n", i+1, lights_on[i] ? "ON" : "OFF");
    }
}

int main() {
    int choice;
    bool valid_choice;
    print_status();

    do {
        valid_choice = true;
        print_menu();
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1 || choice <= 0 || choice > NUM_LIGHTS+1) {
            printf("Invalid choice. Please try again.\n");
            valid_choice = false;
        }
        else if (choice <= NUM_LIGHTS) {
            lights_on[choice-1] = !lights_on[choice-1];
            printf("Light %d is now %s.\n", choice, lights_on[choice-1] ? "ON" : "OFF");
            print_status();
        }
    } while (choice != NUM_LIGHTS+1 || !valid_choice);

    printf("Exiting program.\n");
    return 0;
}