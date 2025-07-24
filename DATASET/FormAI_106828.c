//FormAI DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a car
typedef struct {
    char make[50];
    char model[50];
    int year;
} Car;

// Define the structure for a car dealership
typedef struct {
    char name[50];
    Car inventory[100];
    int num_cars;
} Dealership;

// Main function to run the program
int main()
{
    // Create some example car data
    Car honda_civic = {"Honda", "Civic", 2018};
    Car toyota_camry = {"Toyota", "Camry", 2019};
    Car ford_mustang = {"Ford", "Mustang", 2020};

    // Create a dealership called "Best Deals"
    Dealership best_deals = {"Best Deals", {honda_civic, toyota_camry, ford_mustang}, 3};

    // Print the name of the dealership
    printf("Welcome to %s\n", best_deals.name);

    // Print the cars in the dealership's inventory
    printf("We have the following cars in stock:\n");
    for (int i = 0; i < best_deals.num_cars; i++) {
        printf("%d. %d %s %s\n", i+1, best_deals.inventory[i].year, best_deals.inventory[i].make, best_deals.inventory[i].model);
    }

    // Add a new car to the dealership's inventory
    Car chevy_impala = {"Chevrolet", "Impala", 2017};
    best_deals.inventory[best_deals.num_cars] = chevy_impala;
    best_deals.num_cars++;

    // Print the cars in the dealership's inventory again
    printf("We now have the following cars in stock:\n");
    for (int i = 0; i < best_deals.num_cars; i++) {
        printf("%d. %d %s %s\n", i+1, best_deals.inventory[i].year, best_deals.inventory[i].make, best_deals.inventory[i].model);
    }
    
    // Sell a car from the dealership's inventory
    printf("We just sold the %d %s %s\n", best_deals.inventory[1].year, best_deals.inventory[1].make, best_deals.inventory[1].model);
    for (int i = 1; i < best_deals.num_cars-1; i++) {
        best_deals.inventory[i] = best_deals.inventory[i+1];
    }
    best_deals.num_cars--;

    // Print the cars in the dealership's inventory one more time
    printf("We now have the following cars in stock:\n");
    for (int i = 0; i < best_deals.num_cars; i++) {
        printf("%d. %d %s %s\n", i+1, best_deals.inventory[i].year, best_deals.inventory[i].make, best_deals.inventory[i].model);
    }

    return 0;
}