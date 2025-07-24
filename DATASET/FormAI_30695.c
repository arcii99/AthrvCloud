//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Constants */
#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0 /* Earth's Radius in Kilometers */

/* Function Prototypes */
double to_radians(double degrees);
double haversine(double lat1, double lat2, double lon1, double lon2);
void print_instructions();
void print_map();
void start_navigation(double lat1, double lon1, double lat2, double lon2);

/* Main Function */
int main()
{
    int choice = 1; /* User's Choice */
    double lat1, lon1, lat2, lon2; /* Latitude and Longitude of User's Location and Destination */

    while (choice != 0) /* Loop Until User Chooses to Exit */
    {
        /* Print Navigation Menu */
        printf("\nGPS Navigation Simulation\n\n");
        printf("1. Start Navigation\n");
        printf("2. Print Route Map\n");
        printf("0. Exit\n\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                /* Get Coordinates */
                printf("\nEnter Your Location (Latitude,Longitude): ");
                scanf("%lf,%lf", &lat1, &lon1);

                printf("\nEnter Your Destination (Latitude,Longitude): ");
                scanf("%lf,%lf", &lat2, &lon2);

                /* Start Navigation */
                start_navigation(lat1, lon1, lat2, lon2);
                break;

            case 2:
                /* Print Route Map */
                print_map();
                break;

            case 0:
                /* Exit Program */
                printf("\nThank You for Using GPS Navigation Simulation!\n\n");
                break;

            default:
                /* Invalid Choice */
                printf("\nInvalid Choice. Please Try Again.\n\n");
        }
    }

    return 0; /* Exit Program */
}

/* Converts Degrees to Radians */
double to_radians(double degrees)
{
    return degrees * PI / 180.0;
}

/* Calculates the Haversine Distance between Two Points */
double haversine(double lat1, double lat2, double lon1, double lon2)
{
    double dlat, dlon, a, c;

    dlat = to_radians(lat2 - lat1);
    dlon = to_radians(lon2 - lon1);

    a = pow(sin(dlat / 2), 2) + cos(to_radians(lat1)) * cos(to_radians(lat2)) * pow(sin(dlon / 2), 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

/* Prints Navigation Instructions */
void print_instructions()
{
    printf("\nFollow the Directions Below:\n\n");
    printf("1. Head North for 100 Meters\n");
    printf("2. Turn Left and Head West for 200 Meters\n");
    printf("3. Turn Right and Head North for 300 Meters\n");
    printf("4. Turn Left and Head West for 400 Meters\n");
    printf("5. Turn Right and Head North for 500 Meters\n\n");
}

/* Prints Route Map */
void print_map()
{
    printf("\nMAP:\n\n");
    printf("       N\n");
    printf("       ^\n");
    printf("  W <-----> E\n");
    printf("       |\n");
    printf("       S\n\n");
}

/* Starts Navigation */
void start_navigation(double lat1, double lon1, double lat2, double lon2)
{
    double distance = haversine(lat1, lat2, lon1, lon2); /* Calculate Distance */
    double bearing = atan2(sin(to_radians(lon2 - lon1)) * cos(to_radians(lat2)), cos(to_radians(lat1)) * sin(to_radians(lat2)) - sin(to_radians(lat1)) * cos(to_radians(lat2)) * cos(to_radians(lon2 - lon1))); /* Calculate Bearing */

    /* Print Navigation Instructions and Distance */
    printf("\nStarting Navigation...\n");
    printf("Distance: %.2f Kilometers\n", distance);
    print_instructions();

    /* Print Final Destination */
    printf("You Have Reached Your Destination!\n");
}