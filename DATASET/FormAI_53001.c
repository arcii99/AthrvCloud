//FormAI DATASET v1.0 Category: Temperature monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get random temperature value
int getTemp() {
    int temp = (rand() % (35 - 15 + 1)) + 15;
    return temp;
}

int main() {
    int temp;
    time_t now;
    srand(time(NULL));
  
    printf("Temperature Monitor\n");
    while(1) {
        // get current temperature
        temp = getTemp();
      
        // get current time
        now = time(NULL);
        printf("Current Temperature: %dC\t%s", temp, ctime(&now));
      
        // wait for 10 seconds
        sleep(10);
    }
  
    return 0;
}