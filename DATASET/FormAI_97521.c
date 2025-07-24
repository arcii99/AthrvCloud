//FormAI DATASET v1.0 Category: Weather simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    float temperature;
    float humidity;
    float pressure;
} WeatherData;

void displayWeatherData(WeatherData data) {
    printf("Temperature: %.2f C\n", data.temperature);
    printf("Humidity: %.2f %%\n", data.humidity);
    printf("Pressure: %.2f hPa\n", data.pressure);
}

// simulate a random weather condition
void simulateNextWeatherCondition() {
    WeatherData data;
    data.temperature = (float)(rand() % 100 - 50); // temperature between -50C and 50C
    data.humidity = (float)(rand() % 100); // humidity between 0% and 100%
    data.pressure = (float)(rand() % 2000 + 90000); // pressure between 90,000 hPa and 91,999 hPa
    printf("Simulating next weather condition...\n");
    displayWeatherData(data);
}

int main() {
    srand(time(NULL)); // seed random number generator with current time
    printf("Starting weather simulation...\n");
    simulateNextWeatherCondition(); // simulate initial weather condition
    while (1) {
        printf("Press enter to simulate next weather condition, or type 'exit' to stop.\n");
        char input[10];
        fgets(input, 10, stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        simulateNextWeatherCondition();
    }
    printf("Exiting weather simulation...\n");
    return 0;
}