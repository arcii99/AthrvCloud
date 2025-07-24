//FormAI DATASET v1.0 Category: Temperature monitor ; Style: recursive
#include <stdio.h>

float getTemperature();
void monitorTemperature();
void checkTemp(float temperature);

int main() {
    monitorTemperature();
    return 0;
}

float getTemperature() {
    float temperature;
    printf("Enter the current temperature: ");
    scanf("%f", &temperature);
    return temperature;
}

void monitorTemperature() {
    float temperature = getTemperature();
    checkTemp(temperature);
}

void checkTemp(float temperature) {
    if (temperature < 0) {
        printf("Temperature is below freezing point.\n");
    }
    else if (temperature >= 0 && temperature < 10) {
        printf("Temperature is very cold. Please wear warm clothes.\n");
        monitorTemperature();
    }
    else if (temperature >= 10 && temperature < 20) {
        printf("Temperature is cold. A light jacket is recommended.\n");
        monitorTemperature();
    }
    else if (temperature >= 20 && temperature < 30) {
        printf("Temperature is moderate. Enjoy the weather!\n");
        monitorTemperature();
    }
    else if (temperature >= 30 && temperature < 40) {
        printf("Temperature is hot. Please hydrate yourself.\n");
        monitorTemperature();
    }
    else {
        printf("Temperature is extremely high. Seek medical attention immediately.\n");
        monitorTemperature();
    }
}