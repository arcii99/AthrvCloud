//FormAI DATASET v1.0 Category: Smart home automation ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temperature = 0;
    int humidity = 0;
    int lights_on = 0;
    
    while(1){
        printf("Current temperature is %d degrees Celcius. Enter new temperature: ", temperature);
        scanf("%d", &temperature);
        printf("Current humidity is %d percent. Enter new humidity: ", humidity);
        scanf("%d", &humidity);
        printf("Lights are currently %s. Enter 1 to turn on or 0 to turn off: ", lights_on ? "on" : "off");
        scanf("%d", &lights_on);

        if (temperature > 25 && !lights_on) {
            printf("It is getting too hot, turning on lights to cool down.\n");
            lights_on = 1;
        } else if (temperature < 20 && lights_on) {
            printf("It is getting too cold, turning off lights to conserve energy.\n");
            lights_on = 0;
        }

        if (humidity > 70 && !lights_on) {
            printf("It is getting too humid, turning on lights to remove moisture.\n");
            lights_on = 1;
        } else if (humidity < 30 && lights_on) {
            printf("It is getting too dry, turning off lights to conserve energy.\n");
            lights_on = 0;
        }
        
        printf("\n");
        system("pause");
        system("cls");
    }

    return 0;
}