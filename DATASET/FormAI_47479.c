//FormAI DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

/*
 * A program that helps farmers calculate the total cost of planting crops
 * and predicts the expected yield and revenue.
 */

int main()
{
    float seed_cost, fertilizer_cost, pesticide_cost, land_size, yield, revenue, total_cost;
    int number_of_crops;

    // Get input from user
    printf("Enter the cost of seeds (per pound): ");
    scanf("%f", &seed_cost);

    printf("Enter the cost of fertilizer (per bag): ");
    scanf("%f", &fertilizer_cost);

    printf("Enter the cost of pesticide (per gallon): ");
    scanf("%f", &pesticide_cost);

    printf("Enter the size of land (in acres): ");
    scanf("%f", &land_size);

    printf("Enter the number of crops per acre: ");
    scanf("%d", &number_of_crops);

    // Calculate the total cost of planting
    total_cost = (seed_cost * number_of_crops * land_size) + (fertilizer_cost * land_size) + (pesticide_cost * land_size);

    // Predict the expected yield and revenue
    yield = number_of_crops * land_size * 0.8;
    revenue = yield * 2.5;

    // Display the results
    printf("\nTotal planting cost: $%.2f\n", total_cost);
    printf("Predicted yield: %.2f crops\n", yield);
    printf("Expected revenue: $%.2f\n", revenue);

    return 0;
}