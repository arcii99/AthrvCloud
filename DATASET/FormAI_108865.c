//FormAI DATASET v1.0 Category: Temperature monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float temperature = 0.0;
    unsigned int seed = time(0);
    srand(seed);
    
    while(1) {
        int randomNum = rand() % 100 + 1;
        temperature = (float) randomNum * 2.5;
        
        printf("My love, the temperature outside is %.2f degrees Celsius.\n", temperature);
        
        if (temperature >= 25.0 && temperature <= 30.0) {
            printf("This temperature is perfect just like you.\n");
        } else if (temperature > 30.0) {
            printf("It's getting a little too hot out here, but I will cool you off if you need me to.\n");
        } else {
            printf("It's a little chilly out here, but I'll warm you up with my love.\n");
        }
        
        printf("----------------------------------\n");
        sleep(5);
    }
    
    return 0;
}