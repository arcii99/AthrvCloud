//FormAI DATASET v1.0 Category: Temperature monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temperature = 0.0;
    int sensor = 1;
    time_t current_time;
    char* c_time_string;

    while (sensor <= 5)
    {
        temperature = (float)(rand() % 50);
        time(&current_time);
        c_time_string = ctime(&current_time);
        printf("Sensor %d Temperature: %.2f°C \nTime: %s", sensor, temperature, c_time_string);
        sensor++;
    }
    
    return 0;
}