//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int prob = rand() % 100;
    printf("Probability of Alien Invasion: %d%%\n", prob);
    if(prob >= 75)
        printf("We are under high risk of alien invasion. Take necessary measures!\n");
    else if(prob >= 50)
        printf("We are under moderate risk of alien invasion. Be prepared!\n");
    else if(prob >= 25)
        printf("We are under low risk of alien invasion. Stay alert!\n");
    else
        printf("We are at minimal risk of alien invasion. But be cautious!\n");
    return 0;
}