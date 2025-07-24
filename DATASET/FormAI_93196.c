//FormAI DATASET v1.0 Category: Data mining ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{
    int i, j, k, gold[MAX], silver[MAX], num_mining, num_items, quantity[MAX];
    srand(time(NULL));

    // Generate random mining results
    num_mining = rand() % MAX + 1;
    for(i = 0; i < num_mining; i++)
    {
        gold[i] = rand() % 1000 + 1;
        silver[i] = rand() % 5000 + 1;
        printf("Mining result %d: %d grams of gold and %d grams of silver\n", i+1, gold[i], silver[i]);
    }

    // Count the number of items
    num_items = 0;
    for(i = 0; i < num_mining; i++)
    {
        // Find gold nuggets
        if(gold[i] > 500)
        {
            quantity[num_items] = gold[i] / 500;
            printf("Found %d gold nuggets in mining result %d\n", quantity[num_items], i+1);
            num_items++;
        }

        // Find silver bars
        if(silver[i] > 1000)
        {
            quantity[num_items] = silver[i] / 1000;
            printf("Found %d silver bars in mining result %d\n", quantity[num_items], i+1);
            num_items++;
        }
    }

    // Display the total quantity of items found
    printf("Total number of items found: %d\n", num_items);

    // Display the quantities of each item found
    for(i = 0; i < num_items; i++)
    {
        if(quantity[i] > 0)
        {
            if(i % 2 == 0)
            {
                printf("You have %d gold nuggets\n", quantity[i]);
            }
            else
            {
                printf("You have %d silver bars\n", quantity[i]);
            }
        }
    }

    return 0;
}