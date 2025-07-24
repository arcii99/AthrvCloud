//FormAI DATASET v1.0 Category: Smart home light control ; Style: calm
#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool lightOn = false;
    int time = 0;
    
    printf("Welcome to Smart Home Light Control!\n");
    
    while (true)
    {
        printf("Current time: %d\n", time);
        
        if (time >= 6 && time <= 11 && !lightOn)
        {
            printf("Turning on lights...\n");
            lightOn = true;
        }
        else if (time >= 20 && time <= 23 && lightOn)
        {
            printf("Turning off lights...\n");
            lightOn = false;
        }
        
        printf("Press 'q' to quit or 'c' to continue...\n");
        char input = getchar();
        
        if (input == 'q')
        {
            printf("Goodbye!\n");
            break;
        }
        else if (input == '\n' || input == 'c')
        {
            time++;
        }
        else
        {
            printf("Invalid input, please try again.\n");
        }
    }
    
    return 0;
}