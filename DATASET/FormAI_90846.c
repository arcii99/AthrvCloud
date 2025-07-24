//FormAI DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define NUM_TRANSACTIONS 100
#define NUM_ITEMS 20

int main()
{
    int transactions[NUM_TRANSACTIONS][NUM_ITEMS];
    int i, j;
    
    //Generate Transactions
    for(i=0; i<NUM_TRANSACTIONS; i++)
    {
        for(j=0; j<NUM_ITEMS; j++)
        {
            transactions[i][j] = rand()%2;
        }
    }
    
    //Generate Itemsets
    int itemsets[NUM_ITEMS][2];
    for(i=0; i<NUM_ITEMS; i++)
    {
        itemsets[i][0] = i;
        itemsets[i][1] = 0;
        for(j=0; j<NUM_TRANSACTIONS; j++)
        {
            if(transactions[j][i] == 1)
            {
                itemsets[i][1]++;
            }
        }
    }
    
    //Sort Itemsets
    int temp;
    for(i=0; i<NUM_ITEMS-1; i++)
    {
        for(j=0; j<NUM_ITEMS-i-1; j++)
        {
            if(itemsets[j][1] < itemsets[j+1][1])
            {
                temp = itemsets[j][1];
                itemsets[j][1] = itemsets[j+1][1];
                itemsets[j+1][1] = temp;
                
                temp = itemsets[j][0];
                itemsets[j][0] = itemsets[j+1][0];
                itemsets[j+1][0] = temp;
            }
        }
    }
    
    //Print Top 5 Items
    printf("Top 5 Items:\n");
    for(i=0; i<5; i++)
    {
        printf("Item %d: %d transactions\n", itemsets[i][0], itemsets[i][1]);
    }
    
    return 0;
}