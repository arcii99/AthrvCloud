//FormAI DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    float temperature;

    // Open the file in write mode
    fptr = fopen("temperature.txt", "w");

    // Check if file was opened successfully
    if(fptr == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Ask the user to enter current temperature
    printf("Enter the current temperature in Celsius: ");
    scanf("%f", &temperature);

    // Write the temperature to the file
    fprintf(fptr, "%.2f", temperature);

    // Close the file
    fclose(fptr);

    printf("Temperature recorded successfully!\n");

    return 0;
}