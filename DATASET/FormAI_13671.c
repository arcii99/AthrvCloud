//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random number to choose the conspiracy theory
    int theory = rand() % 5;
    
    // Print the chosen conspiracy theory
    switch(theory) {
        case 0:
            printf("The government is using chemtrails to control the population.\n");
            break;
        case 1:
            printf("The moon landing was faked by Hollywood to make the US look good during the Cold War.\n");
            break;
        case 2:
            printf("The Illuminati controls everything, from world events to the music industry.\n");
            break;
        case 3:
            printf("The Earth is actually flat and all evidence to the contrary is part of a massive cover-up.\n");
            break;
        case 4:
            printf("Aliens have been secretly living among us for decades and the government knows about it.\n");
            break;
    }
    
    // Generate a random number of supporting "facts" for the conspiracy theory
    int numFacts = rand() % 4 + 1;
    
    // Print the supporting "facts" for the conspiracy theory
    for(int i = 0; i < numFacts; i++) {
        switch(theory) {
            case 0:
                printf("- The chemicals in the chemtrails make people more docile and obedient.\n");
                break;
            case 1:
                printf("- The flag waving in the wind in the moon landing footage proves it was fake.\n");
                break;
            case 2:
                printf("- The all-seeing eye on the dollar bill is a symbol of the Illuminati's power.\n");
                break;
            case 3:
                printf("- The curvature of the Earth can't be seen from ground level, therefore it's flat.\n");
                break;
            case 4:
                printf("- The government has recovered alien technology and is back-engineering it.\n");
                break;
        }
    }
    
    return 0;
}