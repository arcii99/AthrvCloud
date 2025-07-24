//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int curTemp = 20; // starting temperature
    
    while(1) { // loop infinitely
        printf("The current temperature is %d degrees Celsius.\n", curTemp);
        
        if (curTemp <= 10) { // surrealism: temperature is so low that it's freezing more than ice
            printf("The temperature is so low that ice is colder than this!\n");
        } else if (curTemp >= 30) { // surrealism: temperature is so high that birds are hatching in egg cartons
            printf("The temperature is so high that I saw some birds hatching in egg cartons!\n");
        }
        
        sleep(5); // wait 5 seconds before updating temperature
        srand(time(NULL));
        int tempChange = rand() % 5 - 2; // temperature can change by -2, -1, 0, 1, or 2 degrees
        curTemp += tempChange;
    }
    
    return 0;
}