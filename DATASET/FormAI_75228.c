//FormAI DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateTemperature() {
    // Generate temperature between 15°C and 35°C
    int temperature = rand() % 21 + 15;
    return temperature;
}

int generateHumidity() {
    // Generate humidity between 40% and 90%
    int humidity = rand() % 51 + 40;
    return humidity;
}

int generatePressure() {
    // Generate pressure between 990 hPa and 1010 hPa
    int pressure = rand() % 21 + 990;
    return pressure;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Print header
    printf("+----------------------+----------------------+----------------------+\n");
    printf("|      Temperature     |       Humidity       |        Pressure      |\n");
    printf("+----------------------+----------------------+----------------------+\n");

    for(int i = 0; i < 24; i++) {
        // Generate weather values
        int temperature = generateTemperature();
        int humidity = generateHumidity();
        int pressure = generatePressure();

        // Print weather values
        printf("|%22d°C |%22d%% |%22d hPa |\n", temperature, humidity, pressure);

        // Wait for 1 second before generating next weather values
        sleep(1);
    }

    // Print footer
    printf("+----------------------+----------------------+----------------------+\n");

    return 0;
}