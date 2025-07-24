//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: introspective
#include <stdio.h>
#include <math.h>

int main() {
    int option;
    float start_lat, start_lon, end_lat, end_lon, distance;
    char choice;
    
    printf("Welcome to the GPS Navigation Simulation.\n\n");
    printf("Please enter the starting latitude: ");
    scanf("%f", &start_lat);
    printf("Please enter the starting longitude: ");
    scanf("%f", &start_lon);
    printf("Please enter the ending latitude: ");
    scanf("%f", &end_lat);
    printf("Please enter the ending longitude: ");
    scanf("%f", &end_lon);

    distance = sqrt(pow(end_lat - start_lat, 2) + pow(end_lon - start_lon, 2));
    printf("\nDistance between the starting and ending points is %.2f.\n", distance);

    printf("\nWould you like to see a map of the route? (y/n) ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("\nMap of the Route:\n\n");
        printf("\t--------------------\n");
        printf("\t|                    |\n");
        printf("\t|                    |\n");
        printf("\t|                    |\n");
        printf("\t|                    |\n");
        printf("\t|                    |\n");
        printf("\t|                    |\n");
        printf("\t--------------------\n");
        printf("\tStarting Point (%.2f, %.2f)\n", start_lat, start_lon);
        printf("\tEnd Point (%.2f, %.2f)\n", end_lat, end_lon);
    }

    printf("\nWould you like to calculate another route? (1/0) ");
    scanf("%d", &option);

    if (option == 1) {
        main();
    } else {
        printf("\nThank you for using the GPS Navigation Simulation program. Goodbye!\n");
    }

    return 0;
}