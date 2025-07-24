//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to detect intrusion
int detect_intrusion(float temperature, float humidity, float pressure, int motion_detected)
{
    float temp_norm = (temperature - 20) / 10; // normalize temperature to range (-2,2)
    float hum_norm = (humidity - 60) / 40; // normalize humidity to range (-1,1)
    float press_norm = (pressure - 1000) / 500; // normalize pressure to range (-2,2)

    float x1 = temp_norm + hum_norm;
    float x2 = temp_norm - 2 * hum_norm;
    float x3 = temp_norm + press_norm;

    float y = 0.2 * x1 + 0.5 * x2 + 0.3 * x3; // linear combination of inputs
    
    if(motion_detected && y > 0.5) // check for intrusion
        return 1;
    else
        return 0;
}

int main()
{
    float temperature, humidity, pressure;
    int motion_detected;
    int intrusion;

    // Taking input from user
    printf("Enter the temperature, humidity and pressure values: ");
    scanf("%f %f %f", &temperature, &humidity, &pressure);

    // Taking motion detection input from user
    printf("\nEnter 1 if motion is detected, 0 otherwise: ");
    scanf("%d", &motion_detected);

    // Detect intrusion
    intrusion = detect_intrusion(temperature, humidity, pressure, motion_detected);

    // Printing result
    if(intrusion)
        printf("\nIntrusion detected!");
    else
        printf("\nNo intrusion detected");

    return 0;
}