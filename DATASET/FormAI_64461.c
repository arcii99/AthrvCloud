//FormAI DATASET v1.0 Category: Weather simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature[24];
    int humidity[24];
    int wind_speed[24];
    int precipitation[24];
    int i, j;
    srand(time(NULL));
    
    printf("Welcome to the Sherlock Holmes Weather Simulation Program!\n");
    printf("Generating 24 hours of weather data...\n\n");
    
    for(i=0; i<24; i++) {
        temperature[i] = rand() % 25 + 10;
        humidity[i] = rand() % 50 + 50;
        wind_speed[i] = rand() % 30;
        precipitation[i] = rand() % 10;
        
        printf("Hour %d - Temperature: %d°C, Humidity: %d%%, Wind Speed: %d km/h, Precipitation: %d%%\n", i+1, temperature[i], humidity[i], wind_speed[i], precipitation[i]);
    }
    
    printf("\nAnalyzing weather data...\n\n");
    
    // Find the highest and lowest temperature
    int highest_temp = temperature[0];
    int lowest_temp = temperature[0];
    for(i=1; i<24; i++) {
        if(temperature[i] > highest_temp) {
            highest_temp = temperature[i];
        }
        if(temperature[i] < lowest_temp) {
            lowest_temp = temperature[i];
        }
    }
    printf("Highest temperature: %d°C\n", highest_temp);
    printf("Lowest temperature: %d°C\n", lowest_temp);
    
    // Determine the average humidity
    float total_humidity = 0;
    for(i=0; i<24; i++) {
        total_humidity += humidity[i];
    }
    float avg_humidity = total_humidity / 24;
    printf("Average humidity: %.1f%%\n", avg_humidity);
    
    // Find the hour with the highest precipitation
    int highest_precip = precipitation[0];
    int highest_precip_hour = 1;
    for(i=1; i<24; i++) {
        if(precipitation[i] > highest_precip) {
            highest_precip = precipitation[i];
            highest_precip_hour = i+1;
        }
    }
    printf("Highest amount of precipitation (%d%%) was recorded at hour %d\n", highest_precip, highest_precip_hour);
    
    // Determine the average wind speed
    float total_wind_speed = 0;
    for(i=0; i<24; i++) {
        total_wind_speed += wind_speed[i];
    }
    float avg_wind_speed = total_wind_speed / 24;
    printf("Average wind speed: %.1f km/h\n", avg_wind_speed);
    
    printf("\nThank you for using the Sherlock Holmes Weather Simulation Program!\n");
    
    return 0;
}