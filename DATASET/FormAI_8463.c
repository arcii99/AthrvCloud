//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>             
#include <time.h>               
#include <unistd.h>             
#include <signal.h>             

void interrupt_handler(int sig) {    
    fprintf(stderr, "Temperature monitor interrupted\n");
    exit(0);
}

int main() {
    signal(SIGINT, interrupt_handler); 

    srand(time(NULL));

    printf("Starting temperature monitor...\n\n");

    float temperature = 25.0;               
    float upper_limit = 30.0;              
    float lower_limit = 20.0;              

    while (1) {
        float noise = (float)rand() / RAND_MAX * 2.0 - 1.0;   
        temperature += noise;                                 

        printf("Current temperature: %.2f\n", temperature);
        if (temperature > upper_limit) {
            printf("WARNING! Temperature is too high!\n");
        } else if (temperature < lower_limit) {
            printf("WARNING! Temperature is too low!\n");
        }

        sleep(1);  
    }

    return 0;
}