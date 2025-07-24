//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_of_bags, num_of_terminals;
    printf("Enter number of bags: ");
    scanf("%d", &num_of_bags);
    printf("Enter number of terminals: ");
    scanf("%d", &num_of_terminals);
    
    srand(time(0));
    
    // generating random number of bags for each terminal
    int bags_per_terminal[num_of_terminals];
    for(int i=0; i<num_of_terminals; i++)
    {
        bags_per_terminal[i] = rand() % num_of_bags + 1;
    }
    
    // calculating total number of bags
    int total_bags = 0;
    for(int i=0; i<num_of_terminals; i++)
    {
        total_bags += bags_per_terminal[i];
    }
    
    // simulating the baggage handling process
    int remaining_bags = total_bags;
    while(remaining_bags > 0)
    {
        for(int i=0; i<num_of_terminals; i++)
        {
            if(bags_per_terminal[i] > 0)
            {
                printf("Baggage handler at terminal %d is loading a bag onto the plane.\n", i+1);
                bags_per_terminal[i]--;
                remaining_bags--;
            }
        }
    }
    
    printf("All %d bags have been loaded onto the plane.\n", total_bags);
    
    return 0;
}