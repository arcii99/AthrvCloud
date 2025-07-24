//FormAI DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float temp;
    srand(time(0));
    
    for(int i = 1; i <= 10; i++) {
        temp = (float)((rand() % 60) - 20) + (((rand() % 100) * 0.01));
        // generates a random float temperature between -20 and 40
        printf("Temperature %d: %.2f C\n", i, temp);
        if(temp < -10 || temp > 30) {
            printf("WARNING: Temperature Out of Range!\n");
        }
    }
    return 0;
}