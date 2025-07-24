//FormAI DATASET v1.0 Category: Temperature monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int celsius = 0;
    srand(time(NULL)); // seed for random number generation

    printf("*******************************\n");
    printf("*** C Temperature Monitor ****\n");
    printf("*******************************\n");

    while(1) { // infinite loop
        celsius = rand() % 101; // generate random temperature value between 0 and 100
        printf("Current Temperature: %d degrees Celsius\n", celsius);
        if(celsius >= 80) {
            printf("WARNING: Temperature is too high. Cooling system activated.\n");
        }
        else if(celsius <= 20) {
            printf("WARNING: Temperature is too low. Heating system activated.\n");
        }
        else {
            printf("Temperature is within acceptable range.\n");
        }
        printf("************************************************************\n");
        printf("Press any key to continue monitoring temperature or 0 to exit: ");
        char input;
        scanf("%c", &input);
        if(input == '0') {
            printf("Exiting Temperature Monitoring Program.");
            exit(0);
        }
        printf("************************************************************\n");
    }
    return 0;
}