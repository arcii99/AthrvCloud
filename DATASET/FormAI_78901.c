//FormAI DATASET v1.0 Category: Weather simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulateWeather(int days) {
    int temperature, windSpeed, pressure, humidity;
    srand(time(NULL));
    printf("Day\tTemp (C)\tWind (km/h)\tPressure (Pa)\tHumidity (%%)\n"); // print header
    printf("-------------------------------------------------------------\n");
    for (int i = 1; i <= days; i++) {
        temperature = rand() % 31 - 10; // generate temperature between -10 and 20 degrees Celsius
        windSpeed = rand() % 101; // generate wind speed between 0 and 100 km/h
        pressure = rand() % 10001 + 90000; // generate pressure between 90,000 and 100,000 Pa
        humidity = rand() % 101; // generate humidity between 0 and 100%
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i, temperature, windSpeed, pressure, humidity); // print weather data
    }
}

int main() {
    int days;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &days);
    simulateWeather(days);
    return 0;
}