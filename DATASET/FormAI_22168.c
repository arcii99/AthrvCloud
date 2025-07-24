//FormAI DATASET v1.0 Category: Weather simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that recursively simulates weather conditions
void simulateWeather(int day, int temperature) {
    printf("Day %d -> Temperature: %d degrees Celsius\n", day, temperature);
    // Base case: simulate weather for 7 days
    if (day == 7) {
        return;
    }
    // Recursive case: determine temperature for next day
    else {
        int randomNum = rand() % 10; // Generate random number between 0 and 9
        if (randomNum < 5) { // 50% chance of temperature staying the same
            simulateWeather(day+1, temperature);
        }
        else if (randomNum < 8) { // 30% chance of temperature increasing by 1 degree
            simulateWeather(day+1, temperature+1);
        }
        else { // 20% chance of temperature decreasing by 1 degree
            simulateWeather(day+1, temperature-1);
        }
    }
}

int main() {
    srand(time(NULL)); // Set random seed based on current time
    int startingTemperature = 20; // Starting temperature for simulation
    simulateWeather(1, startingTemperature); // Call recursive function to simulate weather
    return 0;
}