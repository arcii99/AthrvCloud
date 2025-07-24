//FormAI DATASET v1.0 Category: Smart home light control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define macros for light control
#define ON 1
#define OFF 0

// Define light structure
struct Light {
    char name[20];
    int state;
};

// Function prototypes
void display_menu();
void turn_on(struct Light *light);
void turn_off(struct Light *light);
void get_state(struct Light *light);

int main() {
    // Initialize lights
    struct Light living_room_light = {"Living Room", OFF};
    struct Light bedroom_light = {"Bedroom", OFF};
    struct Light kitchen_light = {"Kitchen", OFF};
    struct Light bathroom_light = {"Bathroom", OFF};
    
    // Display intro
    printf("Welcome to the Smart Home Light Control System!\n\n");
    
    // Display menu and prompt user for input
    char choice[2];
    do {
        display_menu();
        printf("Enter your choice: ");
        fgets(choice, 2, stdin);
        printf("\n");
        
        // Determine user's choice and call appropriate function
        switch (choice[0]) {
            case '1':
                turn_on(&living_room_light);
                break;
            case '2':
                turn_on(&bedroom_light);
                break;
            case '3':
                turn_on(&kitchen_light);
                break;
            case '4':
                turn_on(&bathroom_light);
                break;
            case '5':
                turn_off(&living_room_light);
                break;
            case '6':
                turn_off(&bedroom_light);
                break;
            case '7':
                turn_off(&kitchen_light);
                break;
            case '8':
                turn_off(&bathroom_light);
                break;
            case '9':
                get_state(&living_room_light);
                break;
            case '10':
                get_state(&bedroom_light);
                break;
            case '11':
                get_state(&kitchen_light);
                break;
            case '12':
                get_state(&bathroom_light);
                break;
            case '0':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice[0] != '0');
    
    return 0;
}

// Display menu
void display_menu() {
    printf("MENU:\n");
    printf("1. Turn Living Room Light On\n");
    printf("2. Turn Bedroom Light On\n");
    printf("3. Turn Kitchen Light On\n");
    printf("4. Turn Bathroom Light On\n");
    printf("5. Turn Living Room Light Off\n");
    printf("6. Turn Bedroom Light Off\n");
    printf("7. Turn Kitchen Light Off\n");
    printf("8. Turn Bathroom Light Off\n");
    printf("9. Get Living Room Light State\n");
    printf("10. Get Bedroom Light State\n");
    printf("11. Get Kitchen Light State\n");
    printf("12. Get Bathroom Light State\n");
    printf("0. Exit Program\n\n");
}

// Turn a light on
void turn_on(struct Light *light) {
    if (light->state == ON) {
        printf("%s Light is already on.\n", light->name);
    } else {
        light->state = ON;
        printf("Turning %s Light on.\n", light->name);
    }
}

// Turn a light off
void turn_off(struct Light *light) {
    if (light->state == OFF) {
        printf("%s Light is already off.\n", light->name);
    } else {
        light->state = OFF;
        printf("Turning %s Light off.\n", light->name);
    }
}

// Get a light's state
void get_state(struct Light *light) {
    if (light->state == ON) {
        printf("%s Light is on.\n", light->name);
    } else {
        printf("%s Light is off.\n", light->name);
    }
}