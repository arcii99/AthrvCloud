//FormAI DATASET v1.0 Category: Weather simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP -10
#define MAX_TEMP 40
#define MAX_YEARS 10

int current_year = 2021;

int generate_random_temperature() {
    return rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
}

void print_temperature(int temp) {
    if (temp < 0) {
        printf("It's really cold outside! Temperature: %d°C\n", temp);
    } else if (temp < 10) {
        printf("It's quite chilly outside. Temperature: %d°C\n", temp);
    } else if (temp < 20) {
        printf("The weather is nice and comfortable. Temperature: %d°C\n", temp);
    } else if (temp < 30) {
        printf("It's getting quite hot outside! Temperature: %d°C\n", temp);
    } else {
        printf("It's scorching hot! Temperature: %d°C\n", temp);
    }
}

void simulate_weather(int years) {
    int yearly_temps[12][31];

    for (int year = 0; year < years; year++) {
        printf("***YEAR %d***\n", current_year);
        for (int month = 0; month < 12; month++) {
            for (int day = 0; day < 31; day++) {
                yearly_temps[month][day] = generate_random_temperature();
            }
        }
        for (int month = 0; month < 12; month++) {
            printf("MONTH %d:\n", month + 1);
            for (int day = 0; day < 31; day++) {
                if (yearly_temps[month][day] != 0) {
                    printf("DAY %d: ", day + 1);
                    print_temperature(yearly_temps[month][day]);
                    yearly_temps[month][day] = 0;
                }
            }
        }
        current_year++;
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to our Grateful C Weather Simulation!\n");
    printf("Sit back and relax while we simulate the weather for the next %d years.\n", MAX_YEARS);
    simulate_weather(MAX_YEARS);
    printf("Thank you for using our Grateful C Weather Simulation! Have a great day!\n");
    return 0;
}