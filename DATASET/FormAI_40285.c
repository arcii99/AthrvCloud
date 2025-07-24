//FormAI DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main() {
    float temperature;
    FILE *fptr;

    // Open file in write mode
    fptr = fopen("temperature.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    printf("Enter the temperature value: ");
    scanf("%f", &temperature);

    // Write temperature value to file
    fprintf(fptr, "%.2f", temperature);

    // Close file
    fclose(fptr);

    // Open file in read mode
    fptr = fopen("temperature.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Read temperature value from file
    fscanf(fptr, "%f", &temperature);

    // Close file
    fclose(fptr);

    // Display temperature value
    printf("Temperature is %.2f\n", temperature);

    return 0;
}