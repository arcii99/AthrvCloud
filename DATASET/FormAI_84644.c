//FormAI DATASET v1.0 Category: Temperature monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#define HEAT_THRESHOLD 25

int main() {
    float temperature;
    printf("Welcome to the C Temperature Monitor\n");
    printf("Monitoring the temperature...\n");

    while(1) {
        system("clear"); //clear the screen
        temperature = rand() % 40; //generate a random temperature between 0-40
        printf("Current temperature: %.2f°C\n", temperature);

        if(temperature > HEAT_THRESHOLD) {
            printf("WARNING: Temperature is above safe threshold of %d°C\n", HEAT_THRESHOLD);
            printf("Please take necessary precautions to cool down the environment\n");
        }

        printf("Press any key to continue monitoring, or press 0 to exit: ");
        char choice = getchar();
        if(choice == '0') {
            printf("Exiting Temperature Monitor...\n");
            break;
        }
    }
    return 0;
}