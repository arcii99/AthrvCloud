//FormAI DATASET v1.0 Category: Smart home automation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main() {
    int light = 0; 
    int tv = 0; 
    int temperature = 20; 
    int humidity = 40; 

    printf("Welcome to your smart home!\n"); 
    printf("The current temperature is %d degrees and the humidity level is %d%%.\n", temperature, humidity); 

    while (1) {
        char input[80]; 

        printf("What would you like to do? (Enter 'help' for options): "); 
        fgets(input, 80, stdin); 

        if (strcmp(input, "help\n") == 0) {
            printf("Available commands:\n"); 
            printf(" - 'light on/off' : turn the lights on or off.\n"); 
            printf(" - 'tv on/off' : turn the TV on or off.\n"); 
            printf(" - 'temperature up/down' : increase or decrease the temperature in the house.\n"); 
            printf(" - 'humidity up/down' : increase or decrease the humidity level in the house.\n"); 
            printf(" - 'exit' : exit the program.\n"); 
        } else if (strcmp(input, "light on\n") == 0) {
            printf("Turning the lights on.\n"); 
            light = 1; 
        } else if (strcmp(input, "light off\n") == 0) {
            printf("Turning the lights off.\n"); 
            light = 0; 
        } else if (strcmp(input, "tv on\n") == 0) {
            printf("Turning the TV on.\n"); 
            tv = 1; 
        } else if (strcmp(input, "tv off\n") == 0) {
            printf("Turning the TV off.\n"); 
            tv = 0; 
        } else if (strcmp(input, "temperature up\n") == 0) {
            printf("Increasing the temperature.\n"); 
            temperature++; 
        } else if (strcmp(input, "temperature down\n") == 0) {
            printf("Decreasing the temperature.\n"); 
            temperature--; 
        } else if (strcmp(input, "humidity up\n") == 0) {
            printf("Increasing the humidity level.\n"); 
            humidity++; 
        } else if (strcmp(input, "humidity down\n") == 0) {
            printf("Decreasing the humidity level.\n"); 
            humidity--; 
        } else if (strcmp(input, "exit\n") == 0) {
            printf("Exiting the program.\n"); 
            exit(0); 
        } else {
            printf("Unknown command. Type 'help' for options.\n"); 
        }

        printf("The current temperature is %d degrees and the humidity level is %d%%.\n", temperature, humidity); 
        if (light) {
            printf("The lights are on.\n"); 
        } else {
            printf("The lights are off.\n"); 
        }
        if (tv) {
            printf("The TV is on.\n"); 
        } else {
            printf("The TV is off.\n"); 
        }
    }

    return 0; 
}