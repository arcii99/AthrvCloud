//FormAI DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>

int main()
{
    int lightStatus = 0; // 0 for OFF, 1 for ON
    int roomNumber;
    
    printf("Enter room number to control the light: ");
    scanf("%d", &roomNumber);
    
    printf("Current status of light in room %d: %s\n", roomNumber, lightStatus == 0 ? "OFF" : "ON");
    
    printf("Enter 1 to turn ON the light and 0 to turn it OFF: ");
    scanf("%d", &lightStatus);
    
    if(lightStatus == 0)
    {
        printf("Turning OFF light in room %d\n", roomNumber);
    }
    else if(lightStatus == 1)
    {
        printf("Turning ON light in room %d\n", roomNumber);
    }
    else
    {
        printf("Invalid input\n");
    }
    
    return 0;
}