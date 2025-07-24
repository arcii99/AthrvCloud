//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: detailed
#include <stdio.h>

float get_probability(float average_speed, int alien_count, int time_to_reach_earth) {
    float probability, distance, time_to_reach_alien;
    
    //calculate distance between Earth and aliens based on alien_count
    distance = 10 * alien_count; //using a dummy formula here
    
    //calculate time it would take for aliens to reach Earth
    time_to_reach_alien = distance / average_speed;
    
    //calculate probability of alien invasion
    probability = 1 - (1 / (time_to_reach_earth / time_to_reach_alien));
    
    return probability;
}

int main() {
    float avg_speed = 100.0;
    int alien_count = 10, time_to_reach_earth = 365;
    float probability;
    
    probability = get_probability(avg_speed, alien_count, time_to_reach_earth);
    
    printf("Probability of an alien invasion is %f", probability);
    
    return 0;
}