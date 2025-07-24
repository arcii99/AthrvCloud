//FormAI DATASET v1.0 Category: Temperature monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature = 0;
    srand(time(NULL));
    
    for(int i = 0; i < 50; i++) {
        temperature = rand() % 101;

        if(temperature < 20) {
            printf("Brrr! The temperature is only %d degrees Celsius.\n", temperature);
        }
        else if(temperature >= 20 && temperature < 35) {
            printf("The temperature is a comfortable %d degrees Celsius.\n", temperature);
        }
        else if(temperature >= 35 && temperature < 40) {
            printf("It's getting hot! The temperature is %d degrees Celsius.\n", temperature);
        }
        else {
            printf("Wow, it's scorching! The temperature is %d degrees Celsius.\n", temperature);
        }
        
        // Wait for 1 second before printing the next temperature reading
        sleep(1);
    }
    
    return 0;
}