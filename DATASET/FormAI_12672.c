//FormAI DATASET v1.0 Category: Smart home automation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FRONT_DOOR_CLOSED 0
#define FRONT_DOOR_OPEN 1

#define LIGHT_OFF 0
#define LIGHT_ON 1

#define THERMOSTAT_ON 0
#define THERMOSTAT_OFF 1

void open_front_door(bool *front_door_status) {
  *front_door_status = FRONT_DOOR_OPEN;
  printf("Front door is now open\n");
}

void close_front_door(bool *front_door_status) {
  *front_door_status = FRONT_DOOR_CLOSED;
  printf("Front door is now closed\n");
}

void turn_light_on(bool *light_status) {
  *light_status = LIGHT_ON;
  printf("Light is now on\n");
}

void turn_light_off(bool *light_status) {
  *light_status = LIGHT_OFF;
  printf("Light is now off\n");
}

void turn_thermostat_on(bool *thermostat_status) {
  *thermostat_status = THERMOSTAT_ON;
  printf("Thermostat is now on\n");
}

void turn_thermostat_off(bool *thermostat_status) {
  *thermostat_status = THERMOSTAT_OFF;
  printf("Thermostat is now off\n");
}

int main() {
    bool front_door_status = FRONT_DOOR_CLOSED;
    bool light_status = LIGHT_OFF;
    bool thermostat_status = THERMOSTAT_OFF;
    
    open_front_door(&front_door_status);
    
    if (front_door_status == FRONT_DOOR_OPEN) {
        turn_light_on(&light_status);
        printf("Light is on, it's probably dark outside\n");
        
        if (light_status == LIGHT_ON) {
            turn_thermostat_on(&thermostat_status);
            printf("Thermostat turned on, it's probably cold inside\n");
            
            close_front_door(&front_door_status);
            printf("Front door is closed, rendering thermostat function useless\n");
            turn_thermostat_off(&thermostat_status);
            printf("Thermostat is off, saving energy\n");
        }
        
        turn_light_off(&light_status);
        printf("Light is off, didn't really need it anyways\n");
    }

    printf("End of program. Goodbye!\n");
    
    return 0;
}