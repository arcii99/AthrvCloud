//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
/* Alien Invasion Probability Calculator */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int invasion_probability;
    int i;
    int random_number;
    srand(time(0));
    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("Please enter the probability of an Alien Invasion (0-100): ");
    scanf("%d", &invasion_probability);
    if(invasion_probability < 0 || invasion_probability > 100)
    {
        printf("Invalid Input! Probability must be between 0-100\n");
        exit(0);
    }

    random_number = rand()%101;  //Generate a random number between 0-100
    printf("Calculating the probability of an Alien Invasion...\n");
    for(i=0;i<5;i++)  //Loop for 5 seconds to simulate the calculation process
    {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n\n");

    if(random_number <= invasion_probability)
    {
        printf("ALERT! Based on our calculations, the probability of an Alien Invasion is %d%%\n", random_number);
        printf("The likelihood of extra-terrestrial life contacting us is high!\n");
    }
    else
    {
        printf("No need to panic... The probability of an Alien Invasion is only %d%%\n", random_number);
        printf("The likelihood of extra-terrestrial life contacting us is low!\n");
    }
    
    return 0;
}