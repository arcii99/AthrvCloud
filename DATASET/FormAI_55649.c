//FormAI DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>
#include <string.h>

typedef struct {
    char light[10];
    char fan[10];
    char ac[10];
} Room;

int main()
{
    Room bedroom, livingroom, bathroom;

    // Initialize default values for all rooms
    strcpy(bedroom.light, "off");
    strcpy(livingroom.light, "off");
    strcpy(bathroom.light, "off");

    strcpy(bedroom.fan, "off");
    strcpy(livingroom.fan, "off");
    strcpy(bathroom.fan, "off");

    strcpy(bedroom.ac, "off");
    strcpy(livingroom.ac, "off");
    strcpy(bathroom.ac, "off");

    // Turn on the living room light
    printf("Turning on the living room light.\n");
    strcpy(livingroom.light, "on");

    // Turn on the bedroom fan and AC
    printf("Turning on the bedroom fan and AC.\n");
    strcpy(bedroom.fan, "on");
    strcpy(bedroom.ac, "on");

    // Turn off the bathroom light and fan
    printf("Turning off the bathroom light and fan.\n");
    strcpy(bathroom.light, "off");
    strcpy(bathroom.fan, "off");

    // Print the current state of all devices in each room
    printf("Bedroom:\n");
    printf("  Light: %s\n", bedroom.light);
    printf("  Fan: %s\n", bedroom.fan);
    printf("  AC: %s\n", bedroom.ac);

    printf("Living Room:\n");
    printf("  Light: %s\n", livingroom.light);
    printf("  Fan: %s\n", livingroom.fan);
    printf("  AC: %s\n", livingroom.ac);

    printf("Bathroom:\n");
    printf("  Light: %s\n", bathroom.light);
    printf("  Fan: %s\n", bathroom.fan);
    printf("  AC: %s\n", bathroom.ac);

    return 0;
}