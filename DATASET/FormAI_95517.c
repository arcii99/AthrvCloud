//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

struct Item{
    int value;
    int weight;
    float ratio;
};

int compare(const void *item1, const void *item2){
    struct Item *a = (struct Item *)item1;
    struct Item *b = (struct Item *)item2;
    return (b->ratio - a->ratio);
}

float fractionalKnapsack(int capacity, struct Item items[], int n){
    qsort(items, n, sizeof(struct Item), compare);

    int currentWeight = 0;
    float finalValue = 0.0;

    for(int i=0; i<n; i++){
        if(currentWeight + items[i].weight <= capacity){
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        }
        else{
            int remainingWeight = capacity - currentWeight;
            float valuePerUnit = items[i].ratio;
            finalValue += (remainingWeight*valuePerUnit);
            break;
        }
    }

    return finalValue;
}

int main(){
    int capacity = 50;
    int n = 4;
    struct Item items[n];

    items[0].value = 60;
    items[0].weight = 10;
    items[0].ratio = items[0].value / items[0].weight;

    items[1].value = 100;
    items[1].weight = 20;
    items[1].ratio = items[1].value / items[1].weight;

    items[2].value = 120;
    items[2].weight = 30;
    items[2].ratio = items[2].value / items[2].weight;

    items[3].value = 240;
    items[3].weight = 40;
    items[3].ratio = items[3].value / items[3].weight;

    float maxValue = fractionalKnapsack(capacity, items, n);
    printf("The maximum value that can be obtained is: %f\n", maxValue);

    return 0;
}