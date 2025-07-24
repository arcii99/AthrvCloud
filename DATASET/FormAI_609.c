//FormAI DATASET v1.0 Category: Weather simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEMP_RANGE 25 //Defines the range of temperature values

//Function to randomly generate temperature values
int generateTemperature(){
    time_t seconds;
    time(&seconds); //Gets the current time in seconds
    srand((unsigned int) seconds); //Sets the seed for the rand function using the current time
    
    return rand() % TEMP_RANGE; //Returns a random temperature between 0 and TEMP_RANGE
}

//Function to display the simulation results
void displayResults(int temps[], int size){
    printf("Weather Simulation Results:\n");
    int i;
    for(i = 0; i < size; i++){
        printf("Temperature at %d: %d degrees Celsius\n", i+1, temps[i]);
    }
}

int main(){
    printf("Welcome to the mind-bending weather simulation program!\n");

    int numDays;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays); //Gets user input for number of days to simulate

    int temperature[numDays]; //Creates an array to hold temperature values for each day

    int i;
    for(i = 0; i < numDays; i++){
        temperature[i] = generateTemperature(); //Generates a random temperature for each day
    }

    displayResults(temperature, numDays); //Displays the results of the simulation
    
    return 0;
}