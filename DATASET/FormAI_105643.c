//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the airport baggage handling simulation game!\n\n");
    
    int num_flights, num_terminals, num_baggage;
    
    printf("How many flights are there today?");
    scanf("%d", &num_flights);
    printf("How many terminals are there?");
    scanf("%d", &num_terminals);
    printf("How many bags need to be loaded?");
    scanf("%d", &num_baggage);
    
    printf("\nGreat! Let's get started.\n");
    
    srand(time(NULL));
    
    int total_bags_loaded = 0;
    
    for (int f = 1; f <= num_flights; f++)
    {
        printf("\nFlight #%d is boarding!\n", f);
        for (int t = 1; t <= num_terminals; t++)
        {
            int bags_loaded = rand() % (num_baggage / num_terminals) + 1;
            total_bags_loaded += bags_loaded;
            printf("\n%d bags have been loaded onto Terminal #%d for Flight #%d.\n", bags_loaded, t, f);
        }
    }
    
    printf("\nAll flights have been boarded and %d bags have been loaded onto planes.\nHave a great day!", total_bags_loaded);
    
    return 0;
}