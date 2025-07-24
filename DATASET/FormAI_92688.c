//FormAI DATASET v1.0 Category: Smart home automation ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define LIVING_ROOM 1
#define BEDROOM 2
#define KITCHEN 3
#define BATHROOM 4

typedef struct {
    int temperature;
    int humidity;
    int light_intensity;
} SensorData;

typedef struct {
    int temperature;
    int humidity;
} ClimateControl;

typedef struct {
    int light_intensity;
} LightControl;

SensorData getSensorData(int room) {
    SensorData data;
    switch(room) {
        case LIVING_ROOM:
            data.temperature = 22;
            data.humidity = 50;
            data.light_intensity = 500;
            break;
        case BEDROOM:
            data.temperature = 20;
            data.humidity = 55;
            data.light_intensity = 300;
            break;
        case KITCHEN:
            data.temperature = 24;
            data.humidity = 45;
            data.light_intensity = 1000;
            break;
        case BATHROOM:
            data.temperature = 23;
            data.humidity = 60;
            data.light_intensity = 700;
            break;
    }
    return data;
}

void printSensorData(SensorData data) {
    printf("Temperature: %d°C, Humidity: %d%%, Light Intensity: %d lux\n", data.temperature, data.humidity, data.light_intensity);
}

void climateControl(ClimateControl *control, SensorData data) {
    if (data.temperature < 20) {
        control->temperature = 22;
    } else if (data.temperature > 25) {
        control->temperature = 20;
    } else {
        control->temperature = data.temperature + 1;
    }
    if (data.humidity < 40) {
        control->humidity = 50;
    } else {
        control->humidity = data.humidity;
    }
}

void lightControl(LightControl *control, SensorData data) {
    if (data.light_intensity > 800) {
        control->light_intensity = 500;
    } else {
        control->light_intensity = data.light_intensity;
    }
}

int main() {
    ClimateControl livingRoomClimate;
    SensorData livingRoomData = getSensorData(LIVING_ROOM);
    climateControl(&livingRoomClimate, livingRoomData);
    printf("Living room climate: Temperature: %d°C, Humidity: %d%%\n", livingRoomClimate.temperature, livingRoomClimate.humidity);

    LightControl kitchenLight;
    SensorData kitchenData = getSensorData(KITCHEN);
    lightControl(&kitchenLight, kitchenData);
    printf("Kitchen light: Light Intensity: %d lux\n", kitchenLight.light_intensity);

    return 0;
}