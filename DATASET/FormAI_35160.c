//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>

int main()
{
    // Initialize variables
    float battery_voltage = 12.5;
    float motor_rpm = 500;
    float speed_mph = 0;
    float speed_kph = 0;
    int gear = 0;
    int is_engine_on = 0;

    // Get user input
    printf("Enter gear (0-5): ");
    scanf("%d", &gear);

    // Start engine
    is_engine_on = 1;

    // Calculate speed based on gear and motor RPM
    if (gear == 0)
    {
        speed_mph = 0;
        speed_kph = 0;
    }
    else
    {
        speed_mph = (motor_rpm * gear) / 375;
        speed_kph = speed_mph * 1.60934;
    }

    // Check if battery voltage is low
    if (battery_voltage < 11.5)
    {
        printf("Warning: Battery voltage is low!\n");
    }

    // Print status
    printf("Engine: %s\n", is_engine_on == 1 ? "On" : "Off");
    printf("Gear: %d\n", gear);
    printf("Speed: %.2f mph | %.2f kph\n", speed_mph, speed_kph);

    return 0;
}