//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include<stdio.h>
#include<stdlib.h>

struct Item{
    int value;
    int weight;
    float ratio;
};

void sort(struct Item arr[], int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(arr[j].ratio < arr[j+1].ratio){
                struct Item temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

float knapsack(struct Item arr[], int n, int capacity){
    float totalBenefit = 0;
    int currentWeight = 0;
    for(int i=0; i<n; i++){
        if(currentWeight + arr[i].weight <= capacity){
            currentWeight += arr[i].weight;
            totalBenefit += arr[i].value;
        }
        else{
            int remainingCapacity = capacity - currentWeight;
            totalBenefit += (remainingCapacity * arr[i].ratio);
            break;
        }
    }
    return totalBenefit;
}

int main(){
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item arr[n];
    printf("Enter the items' values and weights:\n");
    for(int i=0; i<n; i++){
        printf("Item %d - value: ", i+1);
        scanf("%d", &arr[i].value);
        printf("Item %d - weight: ", i+1);
        scanf("%d", &arr[i].weight);
        arr[i].ratio = ((float) arr[i].value) / arr[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    sort(arr, n);

    printf("The maximum benefit of the knapsack is: %.2f", knapsack(arr, n, capacity));
    return 0;
}