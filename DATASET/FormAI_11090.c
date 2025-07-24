//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    //Seed for rand() function
    srand(time(0));

    //Variables for counting the number of successful encounters and total encounters
    int successful_encounters = 0;
    int total_encounters = 0;

    //Variables for input
    int num_planets;
    int num_years;

    //Input
    printf("Enter the number of planets in the galaxy: ");
    scanf("%d", &num_planets);
    printf("Enter the number of years: ");
    scanf("%d", &num_years);

    //Calculate the probability of an alien invasion
    for(int i=0; i<num_planets; i++){
        for(int j=0; j<num_years; j++){
            //Generate a random number between 1 and 100
            int probability = rand()%100 + 1;
            //If the probability is greater than or equal to 90, an alien invasion occurs
            if(probability>=90){
                successful_encounters++;
            }
            total_encounters++;
        }
    }

    //Calculate the probability as a percentage
    float probability_percentage = (float)successful_encounters/total_encounters*100;

    printf("After visiting %d planets for %d years, ", num_planets, num_years);
    printf("the probability of an alien invasion is %.2f%%\n", probability_percentage);

    return 0;
}