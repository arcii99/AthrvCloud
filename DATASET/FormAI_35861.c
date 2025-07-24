//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare global variables
int num_predictions = 0;
char *predictions[10];

// Declare functions
void add_prediction(char *prediction);
void generate_random_prediction();

int main()
{
    // Seed the random generator
    srand(time(NULL));

    // Add predictions to array
    add_prediction("You will become very rich.");
    add_prediction("You will meet your soulmate soon.");
    add_prediction("You will experience a major life change.");
    add_prediction("You will take a trip to a foreign country.");
    add_prediction("You will receive unexpected good news.");
    add_prediction("You will learn something new that will change your life.");
    add_prediction("You will experience a setback, but it will ultimately lead to success.");
    add_prediction("You will make a new friend who will become very important to you.");
    add_prediction("You will find a solution to a problem that has been troubling you for a while.");
    add_prediction("You will achieve a long-term goal you have been working towards.");

    // Call function to generate random prediction
    generate_random_prediction();

    // Print number of predictions made
    printf("\n%d predictions made.\n", num_predictions);

    return 0;
}

// Function to add prediction to array
void add_prediction(char *prediction)
{
    predictions[num_predictions] = prediction;
    num_predictions++;
}

// Function to generate random prediction
void generate_random_prediction()
{
    // Generate random number between 0 and 9
    int random_num = rand() % 10;

    // Print prediction
    printf("\nYour fortune for today is: %s\n", predictions[random_num]);
}