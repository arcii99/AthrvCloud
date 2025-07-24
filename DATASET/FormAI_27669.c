//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int alien_probability;
    int invasion_probability;
    int defense_capability;
    int invasion_threshold;
  
    srand(time(NULL)); // seeding random number generator with time
  
    alien_probability = rand() % 101; // generating probability of alien presence
  
    printf("Alien Presence Probability: %d%%\n", alien_probability);
  
    if (alien_probability >= 50) {
        // calculating invasion probability
        invasion_probability = rand() % 31 + 70;
        printf("Invasion Probability: %d%%\n", invasion_probability);
  
        // getting defense capability from user input
        printf("Enter Defense Capability (0-100): ");
        scanf("%d", &defense_capability);
  
        // calculating invasion threshold
        invasion_threshold = invasion_probability - defense_capability;
  
        if (invasion_threshold >= 50) {
            printf("Invasion Highly Likely. Prepare for defense!\n");
        } else if (invasion_threshold >= 20) {
            printf("Invasion Possible. Improve Defense Capability!\n");
        } else if (invasion_threshold >= 0) {
            printf("Invasion Unlikely. Monitor Alien Activity.\n");
        } else {
            printf("Invasion Not Feasible. No Immediate Threat.\n");
        }
    } else {
        printf("No Alien Presence Detected. Stay Alert.\n");
    }
  
    return 0;
}