//FormAI DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>

/* Define structure for Smart Home */
struct SmartHome {
    char* ownerName;
    int noOfRooms;
    float tempInCelsius;
    int lightingStatus;
    int airConditioningStatus;
};

/* Define function to display Smart Home details */
void displaySmartHomeDetails(struct SmartHome home) {
    printf("Owner Name: %s\n", home.ownerName);
    printf("No. of Rooms: %d\n", home.noOfRooms);
    printf("Temperature: %.2fC\n", home.tempInCelsius);
    printf("Lighting Status: %d\n", home.lightingStatus);
    printf("Air Conditioning Status: %d\n", home.airConditioningStatus);
}

int main() {
    /* Create a Smart Home object */
    struct SmartHome myHome = { "John", 3, 24.5, 0, 1 };

    /* Display initial Smart Home details */
    printf("Initial Smart Home Details:\n");
    displaySmartHomeDetails(myHome);

    /* Simulate turning on the lights */
    myHome.lightingStatus = 1;
    printf("\nAfter turning on the lights:\n");
    displaySmartHomeDetails(myHome);

    /* Simulate adjusting the temperature */
    myHome.tempInCelsius = 22.0;
    printf("\nAfter adjusting the temperature:\n");
    displaySmartHomeDetails(myHome);

    /* Simulate turning on the air conditioning */
    myHome.airConditioningStatus = 1;
    printf("\nAfter turning on the air conditioning:\n");
    displaySmartHomeDetails(myHome);

    return 0;
}