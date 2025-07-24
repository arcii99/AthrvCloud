//FormAI DATASET v1.0 Category: Smart home automation ; Style: shocked
#include <stdio.h>

int main() {
  printf("Welcome to the Smart Home Automation Program!\n");
  
  // Turning on bedroom lights when motion is detected
  int motion_sensor_bedroom = 1;
  int bedroom_lights = 0;
  
  if (motion_sensor_bedroom == 1) {
    bedroom_lights = 1;
    printf("Bedroom lights turned on!\n");
  } else {
    bedroom_lights = 0;
    printf("No motion detected in the bedroom.\n");
  }
  
  // Adjusting the thermostat based on the temperature outside
  int temperature = 75;
  int thermostat_setting = 68;
  
  if (temperature < 68) {
    thermostat_setting -= 2;
    printf("Thermostat setting decreased by 2 degrees.\n");
  } else if (temperature > 72) {
    thermostat_setting += 2;
    printf("Thermostat setting increased by 2 degrees.\n");
  } else {
    printf("Temperature is within comfortable range.\n");
  }
  
  // Automatically watering the plants in the garden
  int moisture_level = 40;
  int watering_system = 0;
  
  if (moisture_level < 30) {
    watering_system = 1;
    printf("Watering system turned on.\n");
  } else {
    watering_system = 0;
    printf("No watering needed at this time.\n");
  }
  
  printf("Thank you for using our Smart Home Automation Program!");
  
  return 0;
}