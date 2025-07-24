//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_CAPACITY 100
#define MAX_IDLE_TIME 10
#define MAX_TRANSFER_TIME 5

int main(){
    int count = 0;
    int num_items = 0;
    int items[MAX_CAPACITY];
    int i;
    int idle_time = 0;
    int transfer_time = 0;

    // seed random number generator
    srand(time(NULL));

    // initialize items array with zeros
    memset(items,0,sizeof(items));

    // generate random number of items
    num_items = rand() % MAX_CAPACITY;

    // populate items array with random items
    for(i=0; i<num_items; i++){
        items[i] = rand() % 1000;
    }

    // print items array
    printf("Items in baggage: ");
    for(i=0; i<num_items; i++){
        printf("%d, ",items[i]);
    }
    printf("\n");

    // simulate transfer of baggage
    printf("Starting Baggage Transfer...\n");
    for(i=0; i<num_items; i++){
        // generate random idle time for worker
        idle_time = rand() % MAX_IDLE_TIME;
        printf("Worker is idle for %d seconds.\n",idle_time);

        // transfer baggage item
        transfer_time = rand() % MAX_TRANSFER_TIME;
        printf("Worker is transferring item %d for %d seconds.\n",items[i],transfer_time);
        printf("Item %d transferred successfully.\n",items[i]);

        // increment count
        count++;
    }

    // print summary
    printf("Baggage Transfer Complete!\n");
    printf("Total items transferred: %d\n",count);

    return 0;
}