//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* random_conspiracy_theory();

int main(void) 
{
    srand(time(NULL)); // set up the random seed
    
    printf("Here's your random conspiracy theory: %s\n", random_conspiracy_theory());
    
    return 0;
}

char* random_conspiracy_theory() 
{
    char* theories[] = {
        "The moon landing was faked by the government to win the space race.",
        "The Illuminati are controlling world events from behind the scenes.",
        "The government is hiding evidence that aliens have visited Earth.",
        "9/11 was an inside job orchestrated by the government.",
        "The Flat Earth Society is right and the Earth is actually flat.",
        "The Illuminati are using chemtrails to control our minds."
    };
    
    int num_theories = sizeof(theories) / sizeof(char*);
    
    int index = rand() % num_theories;
    
    char* random_theory = theories[index];
    
    return random_theory;
}