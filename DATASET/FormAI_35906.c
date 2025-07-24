//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: invasive
#include <stdio.h>
#define MAX 100

// function to simulate the baggage handling
void baggage_handling(int baggage[], int n, int t)
{
    int i, j, temp;
    for(i=0; i<t; i++)
    {
        temp = baggage[0];
        for(j=0; j<n-1; j++)
        {
            baggage[j] = baggage[j+1];
        }
        baggage[n-1] = temp;
    }
}

int main()
{
    int n, t, i;
    int baggage[MAX];

    printf("Enter the number of baggage: ");
    scanf("%d", &n);

    printf("Enter the time to simulate: ");
    scanf("%d", &t);

    printf("Enter the weight of each baggage:\n");
    for(i=0; i<n; i++)
    {
        printf("Baggage %d: ", i+1);
        scanf("%d", &baggage[i]);
    }

    baggage_handling(baggage, n, t);

    printf("Baggage after handling:\n");
    for(i=0; i<n; i++)
    {
        printf("Baggage %d: %d\n", i+1, baggage[i]);
    }

    return 0;
}