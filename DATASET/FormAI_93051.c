//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int probability = 0; // Initialize probability of alien invasion to zero
    int population = 0; // Initialize population of humans in a city to zero
    int defense = 0; // Initialize defense capability of the city to zero

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    printf("Enter the population of the city: ");
    scanf("%d", &population);

    printf("Enter the defense capability of the city (1-10): ");
    scanf("%d", &defense);

    // Generate a random number between 0 and 9 using the time function as a seed
    srand(time(NULL));
    int random_num = rand() % 10;

    if(random_num < 5){ // If random number is less than 5, the probability of invasion is low
        probability = random_num * 10;
    }
    else{ // If random number is greater than or equal to 5, the probability of invasion is high
        probability = (random_num + 1) * 10;
    }

    printf("\nBased on our calculations, the probability of an alien invasion in this city is %d%%.\n", probability);

    // Check if the defense capability of the city is high enough to prevent invasion
    if(defense >= probability/10){
        printf("\nWith the defense capability of %d, the city is able to prevent the invasion from happening.\n", defense);
    }
    else{
        printf("\nWith the defense capability of %d, the city is unable to prevent the invasion from happening.\n", defense);
    }

    return 0;
}