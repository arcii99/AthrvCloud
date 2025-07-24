//FormAI DATASET v1.0 Category: Weather simulation ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//function to generate a random number between two ranges
int generateRandomNumber(int lowerBound, int upperBound) {
    int num = (rand() % (upperBound - lowerBound + 1)) + lowerBound;
    return num;
}

int main() {
    srand(time(0)); //generate a seed for the random number generator based on current time
    int temperature[365], humidity[365], pressure[365], precipitation[365], windSpeed[365];
    //arrays for storing daily weather data for a year
    
    //generating weather data for each day of the year
    for(int i=0; i<365; i++) {
        temperature[i] = generateRandomNumber(-20, 40); //temperature in Celsius
        humidity[i] = generateRandomNumber(30, 90); //humidity in %
        pressure[i] = generateRandomNumber(950, 1050); //pressure in hPa
        precipitation[i] = generateRandomNumber(0, 50); //precipitation in mm
        windSpeed[i] = generateRandomNumber(0, 60); //wind speed in km/h
    }
    
    //calculating average weather data for the year
    int sumTemperature = 0, sumHumidity = 0, sumPressure = 0, sumPrecipitation = 0, sumWindSpeed = 0;
    for(int i=0; i<365; i++) {
        sumTemperature += temperature[i];
        sumHumidity += humidity[i];
        sumPressure += pressure[i];
        sumPrecipitation += precipitation[i];
        sumWindSpeed += windSpeed[i];
    }
    float avgTemperature = (float) sumTemperature / 365.0;
    float avgHumidity = (float) sumHumidity / 365.0;
    float avgPressure = (float) sumPressure / 365.0;
    float avgPrecipitation = (float) sumPrecipitation / 365.0;
    float avgWindSpeed = (float) sumWindSpeed / 365.0;
    
    //calculating standard deviation of weather data for the year
    float stdDevTemperature = 0, stdDevHumidity = 0, stdDevPressure = 0, stdDevPrecipitation = 0, stdDevWindSpeed = 0;
    for(int i=0; i<365; i++) {
        stdDevTemperature += pow(temperature[i] - avgTemperature, 2);
        stdDevHumidity += pow(humidity[i] - avgHumidity, 2);
        stdDevPressure += pow(pressure[i] - avgPressure, 2);
        stdDevPrecipitation += pow(precipitation[i] - avgPrecipitation, 2);
        stdDevWindSpeed += pow(windSpeed[i] - avgWindSpeed, 2);
    }
    stdDevTemperature = sqrt(stdDevTemperature / 365.0);
    stdDevHumidity = sqrt(stdDevHumidity / 365.0);
    stdDevPressure = sqrt(stdDevPressure / 365.0);
    stdDevPrecipitation = sqrt(stdDevPrecipitation / 365.0);
    stdDevWindSpeed = sqrt(stdDevWindSpeed / 365.0);
    
    //displaying the weather statistics for the year
    printf("Weather Statistics for the Year:\n");
    printf("Average Temperature: %.2f C\n", avgTemperature);
    printf("Standard Deviation of Temperature: %.2f C\n", stdDevTemperature);
    printf("Average Humidity: %.2f %%\n", avgHumidity);
    printf("Standard Deviation of Humidity: %.2f %%\n", stdDevHumidity);
    printf("Average Pressure: %.2f hPa\n", avgPressure);
    printf("Standard Deviation of Pressure: %.2f hPa\n", stdDevPressure);
    printf("Average Precipitation: %.2f mm\n", avgPrecipitation);
    printf("Standard Deviation of Precipitation: %.2f mm\n", stdDevPrecipitation);
    printf("Average Wind Speed: %.2f km/h\n", avgWindSpeed);
    printf("Standard Deviation of Wind Speed: %.2f km/h\n", stdDevWindSpeed);
    
    return 0;
}