//FormAI DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// function to convert kilometers to miles
double kmToMiles(double km) {
    double miles = km / 1.609344;
    return miles;
}

// function to convert miles to kilometers
double milesToKm(double miles) {
    double km = miles * 1.609344;
    return km;
}

// main function
int main() {
    int choice;
    double input;
    printf("Welcome to the distance converter!\n");
    while(1) {
        printf("Choose an option:\n1. Convert kilometers to miles\n2. Convert miles to kilometers\n3. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter the distance in kilometers: ");
            scanf("%lf", &input);
            printf("%.2lf kilometers is equal to %.2lf miles\n", input, kmToMiles(input));
        }
        else if(choice == 2) {
            printf("Enter the distance in miles: ");
            scanf("%lf", &input);
            printf("%.2lf miles is equal to %.2lf kilometers\n", input, milesToKm(input));
        }
        else if(choice == 3) {
            printf("Thank you for using the distance converter!\n");
            exit(0);
        }
        else {
            printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}