//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numLuggages, numTerminals, totalLuggages = 0;
    int i,j,k;

    printf("Welcome to the Airport Baggage Handling Simulation!\n");

    printf("Please enter the number of luggages: ");
    scanf("%d", &numLuggages);

    printf("Please enter the number of terminals: ");
    scanf("%d", &numTerminals);

    int airport[numLuggages];

    srand(time(0));

    printf("\nGenerating random luggages...\n");

    for(i=0; i<numLuggages; i++) {
        airport[i] = rand()%numTerminals+1;
        printf("Luggage %d is assigned to Terminal %d.\n", i+1, airport[i]);
    }

    printf("\nProcessing luggages...\n");

    for(i=1; i<=numTerminals; i++) {
        int count = 0;
        printf("\nProcessing Terminal #%d...\n", i);
        for(j=0; j<numLuggages; j++) {
            if(airport[j] == i) {
                printf("Processing Luggage %d on Terminal %d...\n", j+1, i);
                count++;
            }
        }
        printf("Total Luggages Processed in Terminal #%d: %d\n", i, count);
        totalLuggages += count;
    }

    printf("\nAll luggages successfully processed!\n");
    printf("Total Number of Luggages Processed: %d\n", totalLuggages);

    return 0;
}