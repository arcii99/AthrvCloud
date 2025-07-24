//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This function will generate a random number between the given range
int generateRandomNumber(int lower_limit, int upper_limit)
{
    int number;
    number = (rand() % (upper_limit - lower_limit + 1)) + lower_limit;
    return number;
}

//This function will simulate the baggage handling process
void simulateBaggageHandling(int num_of_bags)
{
    int conveyor_belts = generateRandomNumber(1, 5);
    int sorting_systems = generateRandomNumber(1, 3);
    int loading_trucks = generateRandomNumber(1, 10);

    int total_time = (num_of_bags / conveyor_belts) + (num_of_bags / sorting_systems) + (num_of_bags / loading_trucks);

    printf("\n=============================================\n");
    printf("Baggage handling simulation begins...\n");
    printf("Number of bags: %d\n", num_of_bags);
    printf("Number of conveyor belts: %d\n", conveyor_belts);
    printf("Number of sorting systems: %d\n", sorting_systems);
    printf("Number of loading trucks: %d\n", loading_trucks);
    printf("Estimated total time for baggage handling: %d minutes\n", total_time);
    printf("=============================================\n");
}

int main()
{
    srand(time(0)); //seeding the random generator
    int num_of_bags;
    printf("Welcome to Airport Baggage Handling Simulation!\n");
    printf("Please enter the number of bags to be handled: ");
    scanf("%d", &num_of_bags);
    simulateBaggageHandling(num_of_bags);
    return 0;
}