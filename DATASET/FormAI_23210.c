//FormAI DATASET v1.0 Category: Weather simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void generate_weather_data(int num_days, int* temps, int* precipitations);
void display_average_weather(int num_days, int* temps, int* precipitations);

int main() {
    int num_days = 7; // number of days to simulate weather for
    int* temps = malloc(num_days * sizeof(int)); // dynamic array to store temperatures for all days
    int* precipitations = malloc(num_days * sizeof(int)); // dynamic array to store precipitation data for all days
    
    generate_weather_data(num_days, temps, precipitations); // generate random weather data for the given number of days
    
    printf("The average temperature and precipitation over the last %d days are: \n", num_days);
    display_average_weather(num_days, temps, precipitations); // display the average weather values for the given number of days
    
    free(temps); // free the dynamically allocated memory
    free(precipitations);
    
    return 0;
}

// function to generate random weather data for the given number of days
void generate_weather_data(int num_days, int* temps, int* precipitations) {
    srand(time(0)); // seed the random number generator with the current time
    for(int i=0;i<num_days;i++) {
        temps[i] = rand() % 30 + 5; // generate a random temperature between 5 and 34 degrees Celsius
        precipitations[i] = rand() % 30; // generate a random precipitation value between 0 and 30 mm
    }
}

// function to display the average weather values for the given number of days
void display_average_weather(int num_days, int* temps, int* precipitations) {
    float temp_sum = 0.0, precip_sum = 0.0;
    for(int i=0;i<num_days;i++) {
        temp_sum += temps[i];
        precip_sum += precipitations[i];
    }
    float temp_avg = temp_sum / num_days;
    float precip_avg = precip_sum / num_days;
    printf("Temperature: %.2f C\nPrecipitation: %.2f mm\n", temp_avg, precip_avg);
}