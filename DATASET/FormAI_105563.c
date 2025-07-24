//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alien_invasion_probability_calculator(int population_count, int technology_level, int military_strength, int area_size, int years_since_last_invasion){
    
    float p = 0.0;

    p += population_count / 1000000.0;
    p += technology_level * 0.2;
    p += military_strength * 0.1;
    p += area_size / 50.0;
    p -= years_since_last_invasion * 0.05;

    if(p > 0.9){
      return 90 + (int)(10*(1 - exp(-(p-0.9)/0.05)));
    } else if(p < 0){
      return 0;
    } else {
      return (int)(100 * p);
    }
}

int main(){
    srand(time(NULL));
    
    // Example usage of the probability calculator
    int population = rand()%1000000000; // Up to 1 billion people
    int tech = rand()%10;
    int military = rand()%10;
    int area = rand()%1000000;
    int last_invasion = rand()%100;

    int probability = alien_invasion_probability_calculator(population, tech, military, area, last_invasion);

    printf("Population: %d\n", population);
    printf("Technology level: %d\n", tech);
    printf("Military strength: %d\n", military);
    printf("Area size: %d\n", area);
    printf("Years since last invasion: %d\n", last_invasion);
    printf("Probability of an alien invasion: %d%%\n", probability);

    return 0;
}