//FormAI DATASET v1.0 Category: Smart home automation ; Style: random
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Define states of different appliances
enum state {
    OFF,
    ON
};

// Define the structure of the smart home appliance
struct appliance {
    char name[20];
    enum state currentState;
};

int main() {
    struct appliance living_room_lamp = {"Living Room Lamp", OFF};
    struct appliance bedroom_lamp = {"Bedroom Lamp", OFF};
    struct appliance kitchen_light = {"Kitchen Light", OFF};
    struct appliance air_conditioner = {"Air Conditioner", OFF};
    struct appliance tv = {"TV", OFF};
    struct appliance door = {"Door", OFF};
    
    bool isOccupied = false;
    bool isDoorLocked = true;
    int temperature = 25;
    
    // Set a timer to check if the room is occupied every minute
    time_t timer;
    time(&timer);
    int seconds = 0;
    
    while (true) {
        if (time(NULL) > timer) {
            // Check if someone is in the room every minute
            timer = time(NULL);
            seconds++;
            
            if (seconds >= 60) {
                seconds = 0;
                isOccupied = !isOccupied;
            }
            
            // If the room is occupied, turn on the living room lamp and TV, adjust the temperature to 22
            if (isOccupied) {
                living_room_lamp.currentState = ON;
                tv.currentState = ON;
                temperature = 22;
                
                printf("Living room lamp and TV have been turned on.\n");
            } else {
                living_room_lamp.currentState = OFF;
                tv.currentState = OFF;
                
                printf("Living room lamp and TV have been turned off.\n");
            }
        }
        
        // If the door is locked, turn off the air conditioner and kitchen light
        if (isDoorLocked) {
            air_conditioner.currentState = OFF;
            kitchen_light.currentState = OFF;
            
            printf("Air conditioner and kitchen light have been turned off.\n");
        } else {
            if (temperature > 25) {
                air_conditioner.currentState = ON;
            } else {
                air_conditioner.currentState = OFF;
            }
            
            if (living_room_lamp.currentState == ON) {
                kitchen_light.currentState = ON;
            } else {
                kitchen_light.currentState = OFF;
            }
            
            printf("Air conditioner and kitchen light have been turned on/off according to the temperature and living room lamp status.\n");
        }
        
        // Print out the status of all appliances
        printf("%s is %s.\n", living_room_lamp.name, living_room_lamp.currentState == ON ? "ON" : "OFF");
        printf("%s is %s.\n", bedroom_lamp.name, bedroom_lamp.currentState == ON ? "ON" : "OFF");
        printf("%s is %s.\n", kitchen_light.name, kitchen_light.currentState == ON ? "ON" : "OFF");
        printf("%s is %s.\n", air_conditioner.name, air_conditioner.currentState == ON ? "ON" : "OFF");
        printf("%s is %s.\n", tv.name, tv.currentState == ON ? "ON" : "OFF");
        printf("%s is %s.\n", door.name, isDoorLocked ? "locked" : "unlocked");
        printf("The temperature is %d degrees Celsius.\n", temperature);
        
        // Wait for 5 seconds before checking again
        sleep(5);
    }
    
    return 0;
}