//FormAI DATASET v1.0 Category: Smart home light control ; Style: synchronous
#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    int light = 0; // initialize light as 'OFF' 
  
    while (1) // infinite loop 
    { 
        printf("Type 'on' to turn the light on, or 'off' to turn the light off: "); 
        
        char input[10]; 
        scanf("%s", input); // read user input 
        
        if (strcmp(input, "on") == 0) // if user input is 'on' 
        { 
            light = 1; // set light to 'ON' 
            printf("Light is now 'ON'\n"); 
        } 
        else if (strcmp(input, "off") == 0) // if user input is 'off' 
        { 
            light = 0; // set light to 'OFF' 
            printf("Light is now 'OFF'\n"); 
        } 
        else // if user input is not 'on' or 'off' 
        { 
            printf("Invalid input\n"); 
        } 
        
        // wait for 1 second before asking for user input again 
        sleep(1); 
    }
  
    return 0; 
}