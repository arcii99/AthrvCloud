//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
    system("clear");
}

void setTerminalColor(int color) {
    switch(color) {
        case 1:
            printf("\033[34m");
            break;
        case 2:
            printf("\033[31m");
            break;
        case 3:
            printf("\033[32m");
            break;
        case 4:
            printf("\033[33m");
            break;
        default:
            printf("\033[0m");
            break;
    }
}

int getCurrentTemperature() {
    srand(time(0));
    return rand() % (120 - (-20)) + (-20);
}

int main() {
    int temperature = getCurrentTemperature();
    printf("Initializing temperature monitor...\n");
    printf("Temperature: ");
    setTerminalColor(4);
    printf("%d\n", temperature);
    setTerminalColor(0);

    while(1) {
        printf("Checking temperature...\n");
        int newTemperature = getCurrentTemperature();
        if (newTemperature > temperature) {
            clearScreen();
            printf("Temperature has increased!\n");
            printf("New Temperature: ");
            setTerminalColor(2);
            printf("%d\n", newTemperature);
            setTerminalColor(0);
        } else if (newTemperature < temperature) {
            clearScreen();
            printf("Temperature has decreased!\n");
            printf("New Temperature: ");
            setTerminalColor(1);
            printf("%d\n", newTemperature);
            setTerminalColor(0);
        } else {
            clearScreen();
            printf("Temperature is stable.\n");
            printf("Temperature: ");
            setTerminalColor(3);
            printf("%d\n", newTemperature);
            setTerminalColor(0);
        }
        temperature = newTemperature;
        sleep(5); // Wait for 5 seconds
    }

    return 0;
}