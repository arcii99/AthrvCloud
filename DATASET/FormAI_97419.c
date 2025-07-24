//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // The following arrays contain different fortune teller messages
    char* colors[] = {"red", "blue", "green", "yellow", "purple"};
    char* numbers[] = {"1", "2", "3", "4", "5"};
    char* predictions[] = {"You will make a new friend today.", 
                           "You will receive unexpected news.", 
                           "Your hard work will pay off soon.", 
                           "You will encounter a challenge.",
                           "You will find clarity in a difficult situation."};
    
    // Get the current time to generate a random seed
    time_t t;
    srand((unsigned) time(&t));
    
    // Generate random indexes to get a color, number, and prediction
    int color_index = rand() % 5;
    int number_index = rand() % 5;
    int prediction_index = rand() % 5;
    
    // Print the fortune teller message with the randomly chosen color, number, and prediction
    printf("Your fortune teller message is:\n\n");
    printf("Your lucky color is %s.\n", colors[color_index]);
    printf("Your lucky number is %s.\n", numbers[number_index]);
    printf("Your prediction for today is: %s.\n", predictions[prediction_index]);
    
    return 0;
}