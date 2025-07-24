//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int no_of_bags, contd;
    printf("\nEnter the number of bags: ");
    scanf("%d", &no_of_bags);

    for(int i=1; i<=no_of_bags; i++)
    {
        printf("\nBag %d arrives at the conveyor", i);
        sleep(3); //3 second delay
        printf("\nBag %d reaches the end of the conveyor", i);

        printf("\nIs the bag over-sized? (1 - Yes, 0 - No): ");
        scanf("%d", &contd);

        if(contd == 1)
        {
            printf("\nBag %d is over-sized and will be sent to oversized baggage area", i);
        }
        else
        {
            printf("\nBag %d is normal-sized and will be sent to the baggage carousel", i);
        }
    }

    printf("\nAll bags have been handled successfully. Thank you!");

    return 0;
}