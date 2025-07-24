//FormAI DATASET v1.0 Category: Weather simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_WEEKS 4
#define NUM_DAYS 7
#define MIN_TEMP 5
#define MAX_TEMP 25

void print_weather_forecast(int forecast[][NUM_DAYS]);
void generate_forecast(int forecast[][NUM_DAYS]);

void main() {
    srand(time(NULL));
    int forecast[MAX_WEEKS][NUM_DAYS];
    generate_forecast(forecast);
    printf("Welcome to our happy weather simulation program!\n\n");
    print_weather_forecast(forecast);
}

void generate_forecast(int forecast[][NUM_DAYS]) {
    for(int i=0; i<MAX_WEEKS; i++) {
        printf("Generating week %d forecast...\n", i + 1);
        for(int j=0; j<NUM_DAYS; j++) {
            forecast[i][j] = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        }
    }
    printf("\nForecast generated successfully!\n\n");
}

void print_weather_forecast(int forecast[][NUM_DAYS]) {
    printf("Weather Forecast for the next %d weeks:\n\n", MAX_WEEKS);
    for(int i=0; i<MAX_WEEKS; i++) {
        printf("Week %d:\t", i + 1);
        for(int j=0; j<NUM_DAYS; j++) {
            printf("%d°C\t", forecast[i][j]);
        }
        printf("\n");
    }
    printf("\nHope you have a great day!\n");
}