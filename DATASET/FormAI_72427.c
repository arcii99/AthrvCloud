//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

// Structure to store information of items
struct item{
    int value;
    int weight;
    float vw_ratio;
};

// Function to compare the items based on their value to weight ratio
int cmp(const void* a, const void* b){
    struct item* i1 = (struct item*) a;
    struct item* i2 = (struct item*) b;
    float v1 = i1->vw_ratio;
    float v2 = i2->vw_ratio;
    if(v1 > v2)
        return -1;
    else if(v1 < v2)
        return 1;
    else
        return 0;
}

// Function to calculate the maximum value that can be obtained
float knapsack(struct item items[], int capacity, int n){
    qsort(items, n, sizeof(items[0]), cmp);    // Sort the items based on their value to weight ratio

    int i=0;
    float max_value=0.0;
    while(capacity > 0 && i<n){    // Add items to the knapsack until no more items can be added
        if(items[i].weight <= capacity){
            capacity -= items[i].weight;
            max_value += items[i].value;
        }
        else{
            max_value += capacity * items[i].vw_ratio;
            capacity = 0;
        }
        i++;
    }
    return max_value;
}

int main(){
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d",&capacity);

    struct item items[n];
    for(int i=0; i<n; i++){
        printf("\nEnter the value and weight of item %d: ",i+1);
        scanf("%d %d",&items[i].value,&items[i].weight);
        items[i].vw_ratio = (float)items[i].value / items[i].weight;
    }

    float max_value = knapsack(items, capacity, n);
    printf("\nMaximum value that can be obtained = %.2f\n", max_value);

    return 0;
}