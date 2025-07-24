//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_SENSOR_PIN 4
#define VOLTAGE_REFERENCE 5.0
#define ADC_RESOLUTION 1024
#define TEMP_COEFFICIENT 0.01 // 10mV/degree Celsius

float read_temperature() {
  srand(time(0));
  float voltage = (float)rand() / (float)RAND_MAX * VOLTAGE_REFERENCE;
  int adc_value = (int)(voltage / VOLTAGE_REFERENCE * ADC_RESOLUTION);
  float temperature = ((float)adc_value / (float)ADC_RESOLUTION * VOLTAGE_REFERENCE / TEMP_SENSOR_PIN - VOLTAGE_REFERENCE / 2) / TEMP_COEFFICIENT;
  return temperature;
}

int main() {
  float temperature = read_temperature();
  printf("Current temperature: %.2f degrees Celsius\n", temperature);
  return 0;
}