//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //seed the random number generator with the current time
    
    int temperature = rand() % 100; //generate a random starting temperature between 0 and 99 degrees
    int maxTemp = temperature;
    int minTemp = temperature;
    int count = 0;
    
    printf("Temperature Monitor Initializing...\n\n");
    
    while(count < 10) { //monitor temperature for 10 cycles
        printf("Current Temperature: %d degrees Celsius\n", temperature);
        
        if(temperature > maxTemp) {
            maxTemp = temperature; //update maximum temperature if applicable
        }
        
        if(temperature < minTemp) {
            minTemp = temperature; //update minimum temperature if applicable
        }
        
        if(temperature >= 50) {
            printf("WARNING: Temperature is exceeding safe limits!\n");
        }
        
        printf("\n");
        temperature += rand() % 11 - 5; //generate a new temperature within the range of +/- 5 degrees
        
        count++;
    }
    
    printf("Temperature Monitor Summary:\n");
    printf("Maximum Temperature: %d degrees Celsius\n", maxTemp);
    printf("Minimum Temperature: %d degrees Celsius\n", minTemp);
    printf("Average Temperature: %d degrees Celsius\n", (maxTemp + minTemp) / 2);
    
    printf("\nMonitoring complete. Stay safe out there!\n");
    
    return 0;
}