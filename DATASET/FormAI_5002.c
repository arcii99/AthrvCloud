//FormAI DATASET v1.0 Category: Weather simulation ; Style: statistical
// C Program to simulate weather conditions using statistical methods
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 365         // number of days in a year
#define MAX_TEMP 35.0    // maximum temperature in degree Celsius
#define MIN_TEMP -5.0    // minimum temperature in degree Celsius
#define MAX_HUMID 100.0  // maximum humidity
#define MIN_HUMID 0.0    // minimum humidity
#define MAX_WIND 50.0    // maximum wind speed in km/h
#define MIN_WIND 0.0     // minimum wind speed in km/h

// function to generate random number between min and max
double generateRandomNumber(double min, double max) {
    double r = (double)rand() / RAND_MAX;
    return min + r * (max - min);
}

// function to compute mean
double computeMean(double* arr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// function to compute standard deviation
double computeStdDev(double* arr, int n, double mean) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }
    return sqrt(sum / n);
}

int main() {
    // seed random number generator
    srand(time(NULL));

    // generate daily weather data for one year and store in arrays
    double temperature[SIZE];
    double humidity[SIZE];
    double windSpeed[SIZE];
    for (int i = 0; i < SIZE; i++) {
        temperature[i] = generateRandomNumber(MIN_TEMP, MAX_TEMP);
        humidity[i] = generateRandomNumber(MIN_HUMID, MAX_HUMID);
        windSpeed[i] = generateRandomNumber(MIN_WIND, MAX_WIND);
    }

    // compute yearly statistics
    double meanTemp = computeMean(temperature, SIZE);
    double meanHumid = computeMean(humidity, SIZE);
    double meanWind = computeMean(windSpeed, SIZE);
    double stdDevTemp = computeStdDev(temperature, SIZE, meanTemp);
    double stdDevHumid = computeStdDev(humidity, SIZE, meanHumid);
    double stdDevWind = computeStdDev(windSpeed, SIZE, meanWind);

    // print yearly statistics
    printf("Yearly statistics for simulated weather data:\n");
    printf("Mean temperature: %.2f degC\n", meanTemp);
    printf("Standard deviation of temperature: %.2f degC\n", stdDevTemp);
    printf("Mean humidity: %.2f %%\n", meanHumid);
    printf("Standard deviation of humidity: %.2f %%\n", stdDevHumid);
    printf("Mean wind speed: %.2f km/h\n", meanWind);
    printf("Standard deviation of wind speed: %.2f km/h\n", stdDevWind);

    return 0;
}