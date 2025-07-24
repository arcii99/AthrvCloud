//FormAI DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_TEMPERATURES 10

int main() {
    char input[MAX_STRING_LENGTH];
    float temperatures[MAX_TEMPERATURES];
    int num_temperatures = 0;

    printf("Welcome to the post-apocalyptic temperature converter!\n");
    printf("Enter temperatures in Celsius, one at a time. Type 'done' when finished.\n");
    
    // loop until either the maximum number of temperatures is reached or the user inputs "done"
    while (num_temperatures < MAX_TEMPERATURES) {
        printf("Temperature %d: ", num_temperatures + 1);
        fgets(input, MAX_STRING_LENGTH, stdin);
        input[strlen(input) - 1] = '\0';  // remove newline character from input
        
        if (strcmp(input, "done") == 0) {
            break;
        }

        // convert input to a float and store in temperatures array
        float temperature = atof(input);
        temperatures[num_temperatures] = temperature;
        num_temperatures++;
    }

    // print out the converted temperatures in Fahrenheit
    printf("\nCelsius\t\tFahrenheit\n");
    for (int i = 0; i < num_temperatures; i++) {
        float celsius = temperatures[i];
        float fahrenheit = (celsius * 9 / 5) + 32;
        printf("%0.2f\t\t%0.2f\n", celsius, fahrenheit);
    }

    printf("\nStay warm out there in the post-apocalyptic wasteland!\n");
    return 0;
}