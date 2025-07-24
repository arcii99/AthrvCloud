//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float temperature = 0;
    srand(time(NULL));
    
    printf("Welcome to the post-apocalyptic temperature monitoring program.\n");
    printf("You are in charge of monitoring the temperature of the last surviving city.\n");
    printf("The fate of humanity rests on your shoulders.\n");
    
    while(1) {
        temperature = rand() % 40 + 1; // generate random temperature between 1 and 40 degrees Celsius
        printf("Current temperature: %.2f degrees Celsius\n", temperature);
        
        if(temperature >= 35) {
            printf("WARNING: Temperature is extremely high! Evacuate citizens immediately!\n");
        } else if(temperature >= 30) {
            printf("WARNING: Temperature is high! Take precautions to prevent heat stroke.\n");
        } else if (temperature <= 5) {
            printf("WARNING: Temperature is extremely low! Provide adequate insulation to buildings.\n");
        } else if (temperature <= 10) {
            printf("WARNING: Temperature is low! Citizens should wear warm clothing.\n");
        }
        
        printf("\nPress any key to continue monitoring...\n");
        getchar(); // wait for user input
    }

    return 0;
}