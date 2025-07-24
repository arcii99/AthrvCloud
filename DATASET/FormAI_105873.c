//FormAI DATASET v1.0 Category: Temperature monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    system("clear"); //clearing console screen
    printf("\t\tWelcome to Temperature Monitor\n");
    printf("\t\t------------------------------\n");
    printf("\n");
    printf("\t\tPress Enter key to check current temperature\n");
    getchar(); //wait for user input

    srand(time(0)); //setting seed for random number generation
    int temperature = rand() % 50; //generating random temperature between 0-50

    if (temperature > 30) { //checking for high temperature
        printf("\t\tCurrent temperature is: %d°C\n", temperature);
        printf("\t\t---------------------------------\n");
        printf("\n");
        printf("\t\tWARNING! High temperature detected\n");
        printf("\t\tPlease take necessary precautions\n");
    }

    else { //normal temperature
        printf("\t\tCurrent temperature is: %d°C\n", temperature);
        printf("\t\t---------------------------------\n");
        printf("\n");
        printf("\t\tTemperature is normal\n");
        printf("\t\tYou are good to go!\n");
    }

    return 0;
}