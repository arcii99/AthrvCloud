//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: portable
/* A program implementing Fractional Knapsack algorithm in C */

#include <stdio.h>
#include <stdlib.h>

// Structure for storing item details
struct item {
    int value;
    int weight;
    float ratio;    // value/weight ratio
};

// Compare function to sort items based on ratio in non-decreasing order
int cmp(const void *a, const void *b)
{
    // Typecasting void pointers to struct item type pointers
    struct item *ia = (struct item *)a;
    struct item *ib = (struct item *)b;
    return (int)(ib->ratio - ia->ratio);
}

int main()
{
    int n, W, i;
    float profit = 0.0; // Total profit
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);
    
    struct item items[n];
    printf("Enter the value and weight of each item: \n");
    for(i=0; i<n; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / (float)items[i].weight;
    }
    
    // Sorting items based on value/weight ratio
    qsort(items, n, sizeof(struct item), cmp);
    
    // Fractional Knapsack algorithm
    for(i=0; i<n; i++) {
        if(W==0) break;
        if(items[i].weight <= W) {
            W -= items[i].weight;
            profit += items[i].value;
        } else {
            profit += items[i].ratio * (float)W;
            W = 0;
        }
    }
    
    printf("Maximum profit is %.2f\n", profit);
    return 0;
}