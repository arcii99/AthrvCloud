//FormAI DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define TEMP_THRESHOLD 25.0 // temperature threshold

int main() {
    float temp;
    int count = 0;
    
    printf("Temperature Monitor System\n\n");
    
    while(1) {
        // read temperature from sensor
        temp = rand() % 50; // generate random temperature value
        
        printf("Temperature reading: %.2f°C\n", temp);
        
        if(temp > TEMP_THRESHOLD) {
            printf("\nWarning: High Temperature!\n");
            
            count++; // increment count
            if(count == 3) {
                printf("\nAlert: Temperature is consistently high!\n");
                break; // exit loop
            }
        }
        else {
            count = 0; // reset count
        }
        
         // wait for 3 seconds
         sleep(3);
    }
    
    printf("Shutdown Temperature Monitor System\n");
    
    return 0;
}