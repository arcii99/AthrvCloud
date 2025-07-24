//FormAI DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>

float convert_to_cm(float inches);
float convert_to_ft(float meters);

int main() {
    int choice;
    float measurement;

    printf("Select an option: \n");
    printf("1. Convert inches to centimeters\n");
    printf("2. Convert meters to feet\n");

    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter measurement in inches: ");
        scanf("%f", &measurement);
        printf("%.2f inches is equal to %.2f centimeters.", measurement, convert_to_cm(measurement));
    } else if(choice == 2) {
        printf("Enter measurement in meters: ");
        scanf("%f", &measurement);
        printf("%.2f meters is equal to %.2f feet.", measurement, convert_to_ft(measurement));
    } else {
        printf("Invalid choice.");
    }

    return 0;
}

float convert_to_cm(float inches) {
    return inches * 2.54;
}

float convert_to_ft(float meters) {
    return meters * 3.28084;
}