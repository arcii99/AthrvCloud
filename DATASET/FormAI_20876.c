//FormAI DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIGHT_SENSOR 1
#define TEMPERATURE_SENSOR 2
#define LIGHT_CONTROL 3
#define TEMPERATURE_CONTROL 4

int main()
{
    bool isDaytime = true;
    int lightIntensity = 50;
    int temperature = 25;

    printf("Starting Home Automation System...\n\n");

    while (true)
    {
        printf("-------------------------------------------------\n");

        // read light sensor data
        int lightSensorData = readSensorData(LIGHT_SENSOR);
        printf("Light Sensor Data: %d\n", lightSensorData);

        // adjust light control
        if (isDaytime && lightSensorData < lightIntensity/2)
        {
            writeActuatorData(LIGHT_CONTROL, true);
        }
        else if (!isDaytime && lightSensorData < lightIntensity)
        {
            writeActuatorData(LIGHT_CONTROL, true);
        }
        else
        {
            writeActuatorData(LIGHT_CONTROL, false);
        }

        // read temperature sensor data
        int temperatureSensorData = readSensorData(TEMPERATURE_SENSOR);
        printf("Temperature Sensor Data: %d C\n", temperatureSensorData);

        // adjust temperature control
        if (temperatureSensorData < temperature - 2)
        {
            writeActuatorData(TEMPERATURE_CONTROL, true);
        }
        else if (temperatureSensorData > temperature + 2)
        {
            writeActuatorData(TEMPERATURE_CONTROL, false);
        }

        printf("-------------------------------------------------\n\n");

        sleep(1);
    }

    printf("Exiting Home Automation System...\n");

    return 0;
}

int readSensorData(int sensor)
{
    // code to read sensor data based on given sensor type
    int sensorData = 10;
    return sensorData;
}

void writeActuatorData(int actuator, bool value)
{
    // code to write actuator data based on given actuator type
    if (actuator == LIGHT_CONTROL)
    {
        if (value)
        {
            printf("Turning light ON\n");
        }
        else
        {
            printf("Turning light OFF\n");
        }
    }
    else if (actuator == TEMPERATURE_CONTROL)
    {
        if (value)
        {
            printf("Increasing temperature\n");
        }
        else
        {
            printf("Decreasing temperature\n");
        }
    }
}