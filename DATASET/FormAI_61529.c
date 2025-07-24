//FormAI DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <string.h>

int main()
{
    char lightState[10] = "OFF";
    int brightness = 0;
  
    printf("Welcome to your Smart Home Light Control Program.\n");
    printf("-------------------------\n");
    printf("Current Light State: %s\n", lightState);
    printf("Current Brightness Level: %d\n", brightness);
    printf("-------------------------\n");
  
    while(1){
        printf("Type 'ON' to turn the light on or 'OFF' to turn the light off: ");
        scanf("%s", lightState);
        if(strcmp(lightState, "ON") == 0 || strcmp(lightState, "ON\n") == 0)
            break;
    }
  
    printf("Light is now ON and set to default brightness level.\n");
    printf("-------------------------\n");
    
    while(1){
        printf("Type 'OFF' to turn the light off, '+' to increase brightness, or '-' to decrease brightness: ");
        scanf("%s", lightState);
      
        if(strcmp(lightState, "OFF") == 0 || strcmp(lightState, "OFF\n") == 0){
            printf("Turning off the light...light is now OFF.\n");
            break;
        }
        else if(strcmp(lightState, "+") == 0 || strcmp(lightState, "+\n") == 0){
            brightness++;
            printf("Brightness level increased to %d.\n", brightness);
        }
        else if(strcmp(lightState, "-") == 0 || strcmp(lightState, "-\n") == 0){
            brightness--;
            printf("Brightness level decreased to %d.\n", brightness);
        }
        else{
            printf("Invalid input, please try again.\n");
        }
    }
  
    printf("-------------------------\n");
    printf("Thank you for using the Smart Home Light Control Program.\n");
    return 0;
}