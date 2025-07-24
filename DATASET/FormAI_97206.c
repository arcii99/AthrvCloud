//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random temperature value between 0 to 100
float generateTemperature(){
    return (float)(rand() % 101);
}

int main(){

    // Set seed for random number generation
    srand(time(0));

    int n; // Number of temperature readings
    printf("Enter the number of temperature readings: ");
    scanf("%d", &n);

    float sum = 0; // Total temperature sum
    float minTemp = 100; // Minimum temperature
    float maxTemp = 0; // Maximum temperature

    // Generate n temperature readings and calculate statistics
    for(int i=1; i<=n; i++){
        float temp = generateTemperature();
        printf("Temperature reading %d: %.2f\n", i, temp);
        sum += temp;
        if(temp < minTemp){
            minTemp = temp;
        }
        if(temp > maxTemp){
            maxTemp = temp;
        }
    }

    // Calculate average temperature
    float avgTemp = sum/n;

    // Print statistics
    printf("Minimum Temperature: %.2f\n", minTemp);
    printf("Maximum Temperature: %.2f\n", maxTemp);
    printf("Average Temperature: %.2f\n", avgTemp);

    return 0;
}