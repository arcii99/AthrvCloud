//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

struct Location {
    char name[50];
    float latitude;
    float longitude;
};

void navigate(struct Location* current_location, struct Location* destination) {
    float distance = sqrt(pow((destination->latitude - current_location->latitude),2) + pow((destination->longitude - current_location->longitude),2));
    printf("\nDistance to %s: %.2f km",destination->name, distance);
}

int main() {
    struct Location current_location = {"Our Meeting Place", 22.5726, 88.3639};
    struct Location destination1 = {"Nicco Park", 22.5718, 88.3951};
    struct Location destination2 = {"Eco Park", 22.5730, 88.4083};

    printf("Welcome to Romantic GPS Navigation System!");
    printf("\nYour current location is: %s", current_location.name);
    navigate(&current_location, &destination1);
    navigate(&current_location, &destination2);

    printf("\nWhere would you like to go today?\n");
    printf("1. Nicco Park\t2. Eco Park\t3. Enter Coordinates\nEnter Choice: ");

    int choice = 0;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nCalculating route to Nicco Park...");
            navigate(&current_location, &destination1);
            printf("\nYou have arrived at Nicco Park. Enjoy your romantic time together!");
            break;
        case 2:
            printf("\nCalculating route to Eco Park...");
            navigate(&current_location, &destination2);
            printf("\nYou have arrived at Eco Park. Enjoy your romantic time together!");
            break;
        case 3:
            printf("\nEnter Latitude: ");
            scanf("%f", &destination1.latitude);
            printf("\nEnter Longitude: ");
            scanf("%f", &destination1.longitude);
            destination1.name[0] = '\0';
            printf("\nCalculating route to custom coordinates...");
            navigate(&current_location, &destination1);
            printf("\nYou have arrived at your destination. Enjoy your romantic time together!");
            break;
        default:
            printf("\nInvalid choice. Try again.");
            break;
    }

    return 0;
}