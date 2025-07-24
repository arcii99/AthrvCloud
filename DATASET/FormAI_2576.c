//FormAI DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the maximum number of lights in the house
#define MAX_LIGHTS 10

// Struct for each light in the house
typedef struct {
    int id;
    bool state;
    int brightness;
} Light;

// Function prototypes
int getLightIndex(int id);
void toggleLight(int id);
void adjustBrightness(int id, int brightness);
void printMenu();
void printLights();

// Create an array of Lights with default values
Light lights[MAX_LIGHTS] = {
    {1, false, 0},
    {2, false, 0},
    {3, false, 0},
    {4, false, 0},
    {5, false, 0},
    {6, false, 0},
    {7, false, 0},
    {8, false, 0},
    {9, false, 0},
    {10, false, 0}
};

// Main function
int main(void) {
    int choice, id, brightness;
    char input[10];
    printMenu();
    while (true) {
        printf("\nEnter Choice: ");
        fgets(input, 10, stdin);
        choice = atoi(input);
        switch (choice) {
            case 1:
                printLights();
                break;
            case 2:
                printf("Enter Light Id: ");
                fgets(input, 10, stdin);
                id = atoi(input);
                toggleLight(id);
                break;
            case 3:
                printf("Enter Light Id: ");
                fgets(input, 10, stdin);
                id = atoi(input);
                printf("Enter Brightness (0-100): ");
                fgets(input, 10, stdin);
                brightness = atoi(input);
                adjustBrightness(id, brightness);
                break;
            case 4:
                printf("Exiting Program...\n");
                exit(0);
                break;
            default:
                printf("Invalid Choice. Please try again.\n");
                break;
        }
        usleep(100000);
        // Clear the screen and print the menu again
        system("clear");
        printMenu();
    }
    return 0;
}

// Function to get the index of the Light with the given id
int getLightIndex(int id) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Function to toggle the state of a Light
void toggleLight(int id) {
    int index = getLightIndex(id);
    if (index != -1) {
        if (lights[index].state) {
            lights[index].state = false;
            printf("Light %d turned off\n", id);
        } else {
            lights[index].state = true;
            printf("Light %d turned on\n", id);
        }
    } else {
        printf("Invalid Light Id\n");
    }
}

// Function to adjust the brightness of a Light
void adjustBrightness(int id, int brightness) {
    int index = getLightIndex(id);
    if (index != -1) {
        if (brightness < 0 || brightness > 100) {
            printf("Invalid Brightness. Please enter a value between 0 and 100\n");
        } else {
            lights[index].brightness = brightness;
            printf("Brightness of Light %d set to %d\n", id, brightness);
        }
    } else {
        printf("Invalid Light Id\n");
    }
}

// Function to print the menu
void printMenu() {
    printf("Smart Home Light Control\n");
    printf("1. List Lights\n");
    printf("2. Toggle Light\n");
    printf("3. Adjust Brightness\n");
    printf("4. Exit\n");
}

// Function to print the current state of all the Lights
void printLights() {
    printf("ID  State  Brightness\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%d   %s     %d\n", lights[i].id, lights[i].state ? "ON" : "OFF", lights[i].brightness);
    }
}