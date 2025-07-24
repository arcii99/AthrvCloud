//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359 // Define PI constant

// Function prototypes
void showMainMenu();
int convertDegreeToRadian(int degree);
float calculateDistance(float x1, float y1, float x2, float y2);
void flyDrone(float x, float y, float height, int rotation);

int main() {
    int choice, degree, rotation;
    float x1, y1, x2, y2, distance, height;

    do {
        showMainMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1: // Convert degree to radian
                printf("Enter degree value: ");
                scanf("%d", &degree);
                printf("%d degree is equal to %.2f radian\n", degree, convertDegreeToRadian(degree));
                break;
            case 2: // Calculate distance between two points
                printf("Enter x1 and y1: ");
                scanf("%f %f", &x1, &y1);
                printf("Enter x2 and y2: ");
                scanf("%f %f", &x2, &y2);
                distance = calculateDistance(x1, y1, x2, y2);
                printf("The distance between (%.2f, %.2f) and (%.2f, %.2f) is %.2f units\n", x1, y1, x2, y2, distance);
                break;
            case 3: // Fly drone to specific location
                printf("Enter x, y, and height: ");
                scanf("%f %f %f", &x1, &y1, &height);
                printf("Enter rotation in degrees: ");
                scanf("%d", &rotation);
                flyDrone(x1, y1, height, rotation);
                break;
            case 4: // Exit program
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please select again!\n");
        }
    } while(choice != 4);

    return 0;
}

// Function to display the main menu
void showMainMenu() {
    printf("Main menu:\n");
    printf("1. Convert degree to radian\n");
    printf("2. Calculate distance between two points\n");
    printf("3. Fly drone to specific location\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
}

// Function to convert degree value to radian value
int convertDegreeToRadian(int degree) {
    return degree * PI / 180;
}

// Function to calculate the distance between two points
float calculateDistance(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x2-x1),2) + pow((y2-y1),2));
}

// Function to fly the drone to a specific location
void flyDrone(float x, float y, float height, int rotation) {
    printf("Flying drone to location (%.2f, %.2f) at height %.2f meters with rotation of %d degrees\n", x, y, height, rotation);
}