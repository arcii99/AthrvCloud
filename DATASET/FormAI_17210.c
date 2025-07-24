//FormAI DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main()
{
    char command[50];
    int temperature = 25;
    int light_on = 0;
    int fan_on = 0;
    int door_locked = 1;
    
    printf("Welcome to your Smart Home Automation System!\n");
    printf("To get started, say one of the following commands:\n");
    printf("- 'set temperature <deg>' to set the thermostat\n");
    printf("- 'turn on/off light' to control the lights\n");
    printf("- 'turn on/off fan' to control the fan\n");
    printf("- 'lock/unlock door' to control the door lock\n");
    
    while (1) {
        printf("Enter a command: ");
        scanf("%[^\n]%*c", command); 
        
        if (strstr(command, "set temperature")) {
            int temp = atoi(command + 16);
            if (temp < 15 || temp > 30) {
                printf("Invalid temperature setting!\n");
            } else {
                temperature = temp;
                printf("Temperature set to %d degrees Celsius.\n", temperature);
            }
            
        } else if (strstr(command, "turn on light")) {
            light_on = 1;
            printf("Light turned on.\n");
            
        } else if (strstr(command, "turn off light")) {
            light_on = 0;
            printf("Light turned off.\n");
            
        } else if (strstr(command, "turn on fan")) {
            fan_on = 1;
            printf("Fan turned on.\n");
            
        } else if (strstr(command, "turn off fan")) {
            fan_on = 0;
            printf("Fan turned off.\n");
            
        } else if (strstr(command, "lock door")) {
            door_locked = 1;
            printf("Door locked.\n");
            
        } else if (strstr(command, "unlock door")) {
            door_locked = 0;
            printf("Door unlocked.\n");
            
        } else {
            printf("Invalid command!\n");
        }
    }
    
    return 0;
}