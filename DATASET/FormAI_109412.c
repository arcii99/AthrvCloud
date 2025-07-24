//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Alien Invasion Probability Calculator
    // By [Your Name]
    // Post-Apocalyptic Edition
    
    srand(time(NULL));
    
    int has_travelled_space = rand() % 2; // 0 or 1
    int tech_level = rand() % 10; // 0 to 9
    
    float alien_inv_prob = 0;
    
    printf("==============================\n");
    printf("ALIEN INVASION PROBABILITY CALCULATOR\n");
    printf("POST-APOCALYPTIC EDITION\n");
    printf("==============================\n");
    
    printf("Has humanity travelled through space? ");
    if(has_travelled_space){
        printf("Yes\n");
        alien_inv_prob += 0.3;
    }
    else{
        printf("No\n");
    }
    
    printf("What is humanity's technological level? ");
    switch(tech_level){
        case 0:
        case 1:
        case 2:
            printf("Primitive\n");
            alien_inv_prob += 0.1;
            break;
        case 3:
        case 4:
        case 5:
            printf("Mid-level\n");
            alien_inv_prob += 0.2;
            break;
        case 6:
        case 7:
        case 8:
            printf("Advanced\n");
            alien_inv_prob += 0.3;
            break;
        case 9:
            printf("Super-advanced\n");
            alien_inv_prob += 0.5;
            break;
        default:
            break;
    }
    
    printf("Calculating probability...\n");
    
    // Additional factors affecting probability calculation
    // ...

    printf("ALIEN INVASION PROBABILITY: %.2f %%\n", alien_inv_prob*100);
    printf("==============================\n");
    
    return 0;
}