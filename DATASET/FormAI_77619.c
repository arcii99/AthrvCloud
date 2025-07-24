//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp;
    
    printf("Cyber Temp Monitor v1.0\n");
    
    while(1) {
        //generate random temperature from -50 to 100 degrees Celsius
        srand(time(NULL));
        temp = (rand() % 151) - 50;
        
        //display current temperature
        printf("Current temperature: %d\n", temp);
        
        if(temp < 0) {
            printf("Warning! Temperature is below freezing.\n");
        }
        else if(temp > 70) {
            printf("Warning! Temperature is above safe operating range.\n");
        }
        else {
            printf("Temperature within normal operating range.\n");
        }
        
        //wait for 5 seconds before checking temperature again
        sleep(5);
    }
    
    return 0;
}